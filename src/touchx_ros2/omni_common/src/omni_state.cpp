/*
 *  Copyright (c) 2022 Ivo Dekker ACRO Diepenbeek KULeuven

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include <urdf_model/model.h>
#include "sensor_msgs/msg/joint_state.hpp"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <chrono>
#include <sstream>
#include <unistd.h>

#include <HL/hl.h>
#include <HD/hd.h>
#include <HDU/hduError.h>
#include <HDU/hduVector.h>
#include <HDU/hduMatrix.h>
#include <HDU/hduQuaternion.h>
#define BT_EULER_DEFAULT_ZYX
#include <bullet/LinearMath/btMatrix3x3.h>

#include "omni_msgs/msg/omni_button_event.hpp"
#include "omni_msgs/msg/omni_feedback.hpp"
#include "omni_msgs/msg/omni_state.hpp"
#include <pthread.h>

float prev_time;
int calibrationStyle;

struct OmniState
{
    hduVector3Dd position; // 3x1 vector of position
    hduVector3Dd velocity; // 3x1 vector of velocity
    hduVector3Dd inp_vel1; // 3x1 history of velocity used for filtering velocity estimate
    hduVector3Dd inp_vel2;
    hduVector3Dd inp_vel3;
    hduVector3Dd out_vel1;
    hduVector3Dd out_vel2;
    hduVector3Dd out_vel3;
    hduVector3Dd pos_hist1; // 3x1 history of position used for 2nd order backward difference estimate of velocity
    hduVector3Dd pos_hist2;
    hduQuaternion rot;
    hduVector3Dd joints;
    hduVector3Dd force; // 3 element double vector force[0], force[1], force[2]
    float thetas[7];
    int buttons[2];
    int buttons_prev[2];
    bool lock;
    bool close_gripper;
    hduVector3Dd lock_pos;
    double units_ratio;
};

class PhantomROS
{

public:
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<omni_msgs::msg::OmniState>::SharedPtr state_publisher;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher;
    rclcpp::Publisher<omni_msgs::msg::OmniButtonEvent>::SharedPtr button_publisher;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_publisher;
    rclcpp::Subscription<omni_msgs::msg::OmniFeedback>::SharedPtr haptic_sub;
    std::string omni_name, ref_frame, units;
    int publish_rate;

    int test_i = 0;

    OmniState *state;
    rclcpp::TimerBase::SharedPtr pub_timer;

    PhantomROS(std::shared_ptr<rclcpp::Node> node)
    {
        node_ = node;
        node_->declare_parameter<std::string>("~omni_name", "phantom");
        node_->declare_parameter<std::string>("~reference_frame", "/map");
        node_->declare_parameter<std::string>("~units", "mm");
        node_->declare_parameter<int>("~publish_rate", 1000);
        node_->get_parameter<std::string>("~omni_name", omni_name);
        node_->get_parameter<std::string>("~reference_frame", ref_frame);
        node_->get_parameter<std::string>("~units", units);
        node_->get_parameter<int>("~publish_rate", publish_rate);
    }

    void init(OmniState *s)
    {
        // Publish button state on NAME/button
        std::ostringstream stream1;
        stream1 << omni_name << "/button";
        std::string button_topic = std::string(stream1.str());
        button_publisher = node_->create_publisher<omni_msgs::msg::OmniButtonEvent>(button_topic.c_str(), 100);
        // RCLCPP_INFO(node_->get_logger(), "Publishing button events on: " + button_topic);
        RCLCPP_INFO(node_->get_logger(), ("Publishing button events on: " + button_topic).c_str());


        // Publish on NAME/state
        std::ostringstream stream2;
        stream2 << omni_name << "/state";
        std::string state_topic_name = std::string(stream2.str());
        state_publisher = node_->create_publisher<omni_msgs::msg::OmniState>(state_topic_name.c_str(), 1);
        // RCLCPP_INFO(node_->get_logger(), "Publishing omni state on: " + state_topic_name);
        RCLCPP_INFO(node_->get_logger(), ("Publishing omni state on: " + state_topic_name).c_str());

        // Subscribe to NAME/force_feedback
        std::ostringstream stream3;
        stream3 << omni_name << "/force_feedback";
        std::string force_feedback_topic = std::string(stream3.str());
        haptic_sub = node_->create_subscription<omni_msgs::msg::OmniFeedback>(force_feedback_topic.c_str(), 1, std::bind(&PhantomROS::force_callback, this, std::placeholders::_1));
        // RCLCPP_INFO(node_->get_logger(), "listening to: " + force_feedback_topic + " for haptic info");
        RCLCPP_INFO(node_->get_logger(), ("listening to: " + force_feedback_topic + " for haptic info").c_str());

        // Publish on NAME/pose
        std::ostringstream stream4;
        stream4 << omni_name << "/pose";
        std::string pose_topic_name = std::string(stream4.str());
        pose_publisher = node_->create_publisher<geometry_msgs::msg::PoseStamped>(pose_topic_name.c_str(), 1);
        // RCLCPP_INFO(node_->get_logger(), "Publishing pose on: " + pose_topic_name);
        RCLCPP_INFO(node_->get_logger(), ("Publishing pose on: " + pose_topic_name).c_str());

        // Publish on NAME/joint_states
        std::ostringstream stream5;
        stream5 << omni_name << "/joint_states";
        std::string joint_topic_name = std::string(stream5.str());
        joint_publisher = node_->create_publisher<sensor_msgs::msg::JointState>(joint_topic_name.c_str(), 1);
        // RCLCPP_INFO(node_->get_logger(), "Publishing joint state on: " + joint_topic_name);
        RCLCPP_INFO(node_->get_logger(), ("Publishing joint state on: " + joint_topic_name).c_str());

        state = s;
        state->buttons[0] = 0;
        state->buttons[1] = 0;
        state->buttons_prev[0] = 0;
        state->buttons_prev[1] = 0;
        hduVector3Dd zeros(0, 0, 0);
        state->velocity = zeros;
        state->inp_vel1 = zeros;  // 3x1 history of velocity
        state->inp_vel2 = zeros;  // 3x1 history of velocity
        state->inp_vel3 = zeros;  // 3x1 history of velocity
        state->out_vel1 = zeros;  // 3x1 history of velocity
        state->out_vel2 = zeros;  // 3x1 history of velocity
        state->out_vel3 = zeros;  // 3x1 history of velocity
        state->pos_hist1 = zeros; // 3x1 history of position
        state->pos_hist2 = zeros; // 3x1 history of position
        state->lock = false;
        state->close_gripper = false;
        state->lock_pos = zeros;
        if (!units.compare("mm"))
            state->units_ratio = 1.0;
        else if (!units.compare("cm"))
            state->units_ratio = 10.0;
        else if (!units.compare("dm"))
            state->units_ratio = 100.0;
        else if (!units.compare("m"))
            state->units_ratio = 1000.0;
        else
        {
            state->units_ratio = 1.0;
            RCLCPP_WARN(node_->get_logger(), "Unknown units [%s] unsing [mm]", units.c_str());
            units = "mm";
        }
        RCLCPP_INFO(node_->get_logger(), "PHaNTOM position given in [%s], ratio [%.1f]", units.c_str(), state->units_ratio);
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Publishing PHaNTOM state at [%d] Hz", publish_rate);
        pub_timer = node_->create_wall_timer(std::chrono::milliseconds(1), std::bind(&PhantomROS::publish_omni_state, this));
    }

    /*******************************************************************************
     ROS node callback.
     *******************************************************************************/
    void force_callback(const omni_msgs::msg::OmniFeedback::SharedPtr omnifeed)
    {
        ////////////////////Some people might not like this extra damping, but it
        ////////////////////helps to stabilize the overall force feedback. It isn't
        ////////////////////like we are getting direct impedance matching from the
        ////////////////////omni anyway
        state->force[0] = omnifeed->force.x - 0.001 * state->velocity[0];
        state->force[1] = omnifeed->force.y - 0.001 * state->velocity[1];
        state->force[2] = omnifeed->force.z - 0.001 * state->velocity[2];
        
        std::cout<<test_i<<std::endl;
        test_i+=1;
        // state->force[0] = omnifeed->force.x ;
        // state->force[1] = omnifeed->force.y ;
        // state->force[2] = omnifeed->force.z ;

        std::cout<<"omnifeed->force.y:"<<omnifeed->force.y<<std::endl;
        std::cout<<"state->velocity[1]:"<<state->velocity[1]<<std::endl;
        std::cout<<"omnifeed->position.y;"<<state->position<<std::endl;

        state->lock_pos[0] = omnifeed->position.x;
        state->lock_pos[1] = omnifeed->position.y;
        state->lock_pos[2] = omnifeed->position.z;
    }

    void publish_omni_state()
    {
        // Build the state msg
        omni_msgs::msg::OmniState state_msg;
        // Locked
        state_msg.locked = state->lock;
        state_msg.close_gripper = state->close_gripper;
        // Position
        state_msg.pose.position.x = state->position[0];
        state_msg.pose.position.y = state->position[1];
        state_msg.pose.position.z = state->position[2];
        // Orientation
        state_msg.pose.orientation.x = state->rot.v()[0];
        state_msg.pose.orientation.y = state->rot.v()[1];
        state_msg.pose.orientation.z = state->rot.v()[2];
        state_msg.pose.orientation.w = state->rot.s();
        // Velocity
        state_msg.velocity.x = state->velocity[0];
        state_msg.velocity.y = state->velocity[1];
        state_msg.velocity.z = state->velocity[2];
        // TODO: Append Current to the state msg
        state_msg.header.stamp = node_->now();
        state_publisher->publish(state_msg);

        // Publish the JointState msg
        sensor_msgs::msg::JointState joint_state;
        joint_state.header.stamp = node_->now();
        joint_state.name.resize(6);
        joint_state.position.resize(6);
        joint_state.name[0] = "waist";
        joint_state.position[0] = -state->thetas[1];
        joint_state.name[1] = "shoulder";
        joint_state.position[1] = state->thetas[2];
        joint_state.name[2] = "elbow";
        joint_state.position[2] = state->thetas[3];
        joint_state.name[3] = "yaw";
        joint_state.position[3] = -state->thetas[4] + M_PI;
        joint_state.name[4] = "pitch";
        joint_state.position[4] = -state->thetas[5] - 3 * M_PI / 4;
        joint_state.name[5] = "roll";
        joint_state.position[5] = -state->thetas[6] - M_PI;
        joint_publisher->publish(joint_state);

        // Build the pose msg
        geometry_msgs::msg::PoseStamped pose_msg;
        pose_msg.header = state_msg.header;
        pose_msg.header.frame_id = ref_frame;
        pose_msg.pose = state_msg.pose;
        pose_msg.pose.position.x /= 1000.0;
        pose_msg.pose.position.y /= 1000.0;
        pose_msg.pose.position.z /= 1000.0;
        pose_publisher->publish(pose_msg);

        if ((state->buttons[0] != state->buttons_prev[0]) or (state->buttons[1] != state->buttons_prev[1]))
        {
            if (state->buttons[0] == 1)
            {
                state->close_gripper = !(state->close_gripper);
            }
            if (state->buttons[1] == 1)
            {
                state->lock = !(state->lock);
            }
            omni_msgs::msg::OmniButtonEvent button_event;
            button_event.grey_button = state->buttons[0];
            button_event.white_button = state->buttons[1];
            state->buttons_prev[0] = state->buttons[0];
            state->buttons_prev[1] = state->buttons[1];
            button_publisher->publish(button_event);
        }
    }
};

HDCallbackCode HDCALLBACK omni_state_callback(void *pUserData)
{
    OmniState *omni_state = static_cast<OmniState *>(pUserData);
    if (hdCheckCalibration() == HD_CALIBRATION_NEEDS_UPDATE)
    {
        RCLCPP_DEBUG(rclcpp::get_logger("omni_haptic_node"), "Updating calibration...");
        hdUpdateCalibration(calibrationStyle);
    }
    hdBeginFrame(hdGetCurrentDevice());
    // Get transform and angles
    hduMatrix transform;
    hdGetDoublev(HD_CURRENT_TRANSFORM, transform);
    hdGetDoublev(HD_CURRENT_JOINT_ANGLES, omni_state->joints);
    hduVector3Dd gimbal_angles;
    hdGetDoublev(HD_CURRENT_GIMBAL_ANGLES, gimbal_angles);
    // Notice that we are inverting the Z-position value and changing Y <---> Z
    // Position
    omni_state->position = hduVector3Dd(transform[3][0], -transform[3][2], transform[3][1]);
    omni_state->position /= omni_state->units_ratio;
    // Orientation (quaternion)
    hduMatrix rotation(transform);
    rotation.getRotationMatrix(rotation);
    hduMatrix rotation_offset(0.0, -1.0, 0.0, 0.0,
                              1.0, 0.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              0.0, 0.0, 0.0, 1.0);
    rotation_offset.getRotationMatrix(rotation_offset);
    omni_state->rot = hduQuaternion(rotation_offset * rotation);
    // Velocity estimation
    hduVector3Dd vel_buff(0, 0, 0);
    vel_buff = (omni_state->position * 3 - 4 * omni_state->pos_hist1 + omni_state->pos_hist2) / 0.002;                                                                                                                                      //(units)/s, 2nd order backward dif
    omni_state->velocity = (.2196 * (vel_buff + omni_state->inp_vel3) + .6588 * (omni_state->inp_vel1 + omni_state->inp_vel2)) / 1000.0 - (-2.7488 * omni_state->out_vel1 + 2.5282 * omni_state->out_vel2 - 0.7776 * omni_state->out_vel3); // cutoff freq of 20 Hz
    omni_state->pos_hist2 = omni_state->pos_hist1;
    omni_state->pos_hist1 = omni_state->position;
    omni_state->inp_vel3 = omni_state->inp_vel2;
    omni_state->inp_vel2 = omni_state->inp_vel1;
    omni_state->inp_vel1 = vel_buff;
    omni_state->out_vel3 = omni_state->out_vel2;
    omni_state->out_vel2 = omni_state->out_vel1;
    omni_state->out_vel1 = omni_state->velocity;

    //~ // Set forces if locked
    //~ if (omni_state->lock == true) {
    //~ omni_state->force = 0.04 * omni_state->units_ratio * (omni_state->lock_pos - omni_state->position)
    //~ - 0.001 * omni_state->velocity;
    //~ }
    hduVector3Dd feedback;
    // Notice that we are changing Y <---> Z and inverting the Z-force_feedback
    feedback[0] = omni_state->force[0];
    feedback[1] = omni_state->force[2];
    feedback[2] = -omni_state->force[1];

    // for(int i=0;i<3;i++){
    //     std::cout<< i <<feedback[i]<<std::endl;
    // }


    hdSetDoublev(HD_CURRENT_FORCE, feedback);

    // Get buttons
    int nButtons = 0;
    hdGetIntegerv(HD_CURRENT_BUTTONS, &nButtons);
    omni_state->buttons[0] = (nButtons & HD_DEVICE_BUTTON_1) ? 1 : 0;
    omni_state->buttons[1] = (nButtons & HD_DEVICE_BUTTON_2) ? 1 : 0;

    hdEndFrame(hdGetCurrentDevice());

    HDErrorInfo error;
    if (HD_DEVICE_ERROR(error = hdGetError()))
    {
        hduPrintError(stderr, &error, "Error during main scheduler callback");
        if (hduIsSchedulerError(&error))
            return HD_CALLBACK_DONE;
    }

    float t[7] = {0., omni_state->joints[0], omni_state->joints[1],
                  omni_state->joints[2] - omni_state->joints[1], gimbal_angles[0],
                  gimbal_angles[1], gimbal_angles[2]};
    for (int i = 0; i < 7; i++)
        omni_state->thetas[i] = t[i];
    return HD_CALLBACK_CONTINUE;
}

/*******************************************************************************
 Automatic Calibration of Phantom Device - No character inputs
 *******************************************************************************/
void HHD_Auto_Calibration()
{
    int supportedCalibrationStyles;
    HDErrorInfo error;

    hdGetIntegerv(HD_CALIBRATION_STYLE, &supportedCalibrationStyles);
    if (supportedCalibrationStyles & HD_CALIBRATION_ENCODER_RESET)
    {
        calibrationStyle = HD_CALIBRATION_ENCODER_RESET;
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "HD_CALIBRATION_ENCODER_RESET..");
    }
    if (supportedCalibrationStyles & HD_CALIBRATION_INKWELL)
    {
        calibrationStyle = HD_CALIBRATION_INKWELL;
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "HD_CALIBRATION_INKWELL..");
    }
    if (supportedCalibrationStyles & HD_CALIBRATION_AUTO)
    {
        calibrationStyle = HD_CALIBRATION_AUTO;
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_ndoe"), "HD_CALIBRATION_AUTO..");
    }
    if (calibrationStyle == HD_CALIBRATION_ENCODER_RESET)
    {
        do
        {
            hdUpdateCalibration(calibrationStyle);
            RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Calibrating.. (put stylus in well)");
            if (HD_DEVICE_ERROR(error = hdGetError()))
            {
                hduPrintError(stderr, &error, "Reset encoders reset failed.");
                break;
            }
        } while (hdCheckCalibration() != HD_CALIBRATION_OK);
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Calibration complete.");
    }
    while (hdCheckCalibration() != HD_CALIBRATION_OK)
    {
        usleep(1e6);
        if (hdCheckCalibration() == HD_CALIBRATION_NEEDS_MANUAL_INPUT)
            RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Please place the device into the inkwell for calibration");
        else if (hdCheckCalibration() == HD_CALIBRATION_NEEDS_UPDATE)
        {
            RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Calibration updated successfully");
            hdUpdateCalibration(calibrationStyle);
        }
        else
            RCLCPP_FATAL(rclcpp::get_logger("omni_haptic_node"), "Unknown calibration status");
    }
}

int main(int argc, char **argv)
{
    ////////////////////////////////////////////////////////////////
    // Init Phantom
    ////////////////////////////////////////////////////////////////
    HDErrorInfo error;
    HHD hHD;
    hHD = hdInitDevice(HD_DEFAULT_DEVICE);
    if (HD_DEVICE_ERROR(error = hdGetError()))
    {
        // hduPrintError(stderr, &error, "Failed to initialize haptic device");
        RCLCPP_ERROR(rclcpp::get_logger("omni_haptic_node"), "Failed to initialize haptic device"); //: %s", &error);
        return -1;
    }

    RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Found %s.", hdGetString(HD_DEVICE_MODEL_TYPE));
    hdEnable(HD_FORCE_OUTPUT);
    hdStartScheduler();
    if (HD_DEVICE_ERROR(error = hdGetError()))
    {
        RCLCPP_ERROR(rclcpp::get_logger("omni_haptic_node"), "Failed to start the scheduler"); //, &error);
        return -1;
    }
    HHD_Auto_Calibration();

    ////////////////////////////////////////////////////////////////
    // Init ROS
    ////////////////////////////////////////////////////////////////
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = std::make_shared<rclcpp::Node>("omni_haptic_node");
    OmniState state;
    PhantomROS omni_ros(node);

    omni_ros.init(&state);
    hdScheduleAsynchronous(omni_state_callback, &state,
                           HD_MAX_SCHEDULER_PRIORITY);
    
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    RCLCPP_INFO(node->get_logger(), "Ending Session....");
    hdStopScheduler();
    hdDisableDevice(hHD);

    return 0;
}
