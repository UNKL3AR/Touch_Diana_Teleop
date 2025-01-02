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
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/wrench_stamped.hpp"
#include <urdf_model/model.h>
#include "sensor_msgs/msg/joint_state.hpp"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <sstream>

#include <HL/hl.h>
#include <HD/hd.h>
#include <HDU/hduError.h>
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

#include <HDU/hduVector.h>
#include <HDU/hduMatrix.h>

#include "omni_msgs/msg/omni_button_event.hpp"
#include "omni_msgs/msg/omni_feedback.hpp"
#include <pthread.h>

float prev_time;
int calibrationStyle;
#define DEVICE_NAME "Touchx"
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
    hduVector3Dd rot;
    hduVector3Dd joints;
    hduVector3Dd force; // 3 element double vector force[0], force[1], force[2]
    float thetas[7];
    int buttons[2];
    int buttons_prev[2];
    bool lock;
    hduVector3Dd lock_pos;
};

class PhantomROS
{

public:
    std::shared_ptr<rclcpp::Node> node_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_publisher;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub;

    rclcpp::Publisher<omni_msgs::msg::OmniButtonEvent>::SharedPtr button_publisher;
    rclcpp::Subscription<omni_msgs::msg::OmniFeedback>::SharedPtr haptic_sub;
    std::string omni_name;
    std::string sensable_frame_name;
    std::string link_names[7];
    int publish_rate;

    OmniState *state;
    std::shared_ptr<tf2_ros::TransformBroadcaster> br;

    PhantomROS(std::shared_ptr<rclcpp::Node> node)
    {
        node_ = node;
        node_->declare_parameter<std::string>("~omni_name", "phantom");
        node_->get_parameter<std::string>("~omni_name", omni_name);
        node_->declare_parameter<int>("publish_rate", 100);
        node_->get_parameter<int>("publish_rate", publish_rate);
        br = std::make_shared<tf2_ros::TransformBroadcaster>(node_);
    }

    void init(OmniState *s)
    {
        // Publish on NAME/pose
        std::ostringstream stream00;
        stream00 << omni_name << "/pose";
        std::string pose_topic_name = std::string(stream00.str());
        pose_publisher = node_->create_publisher<geometry_msgs::msg::PoseStamped>(
            pose_topic_name.c_str(), 100);

        joint_pub = node_->create_publisher<sensor_msgs::msg::JointState>("joint_states", 1);

        // Publish button state on NAME/button
        std::ostringstream stream0;
        stream0 << omni_name << "/button";
        std::string button_topic = std::string(stream0.str());
        button_publisher = node_->create_publisher<omni_msgs::msg::OmniButtonEvent>(
            button_topic.c_str(), 100);

        // Subscribe to NAME/force_feedback
        std::ostringstream stream01;
        stream01 << omni_name << "/force_feedback";
        std::string force_feedback_topic = std::string(stream01.str());
        haptic_sub = node_->create_subscription<omni_msgs::msg::OmniFeedback>(force_feedback_topic.c_str(), 100,
                                 std::bind(&PhantomROS::force_callback, this, std::placeholders::_1));

        // Frame of force feedback (NAME_sensable)
        std::ostringstream stream2;
        stream2 << omni_name << "_sensable";
        sensable_frame_name = std::string(stream2.str());

        for (int i = 0; i < 7; i++)
        {
            std::ostringstream stream1;
            stream1 << omni_name << "_link" << i;
            link_names[i] = std::string(stream1.str());
        }

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
        state->lock = true;
        state->lock_pos = zeros;
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

        state->lock_pos[0] = omnifeed->position.x;
        state->lock_pos[1] = omnifeed->position.y;
        state->lock_pos[2] = omnifeed->position.z;
    }

    void publish_omni_state()
    {
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
        joint_pub->publish(joint_state);

        // Sample 'end effector' pose
        geometry_msgs::msg::PoseStamped pose_stamped;
        pose_stamped.header.frame_id = link_names[6].c_str();
        pose_stamped.header.stamp = node_->now();
        pose_stamped.pose.position.x = 0.0; // was 0.03 to end of phantom
        pose_stamped.pose.orientation.w = 1.;
        pose_publisher->publish(pose_stamped);

        if ((state->buttons[0] != state->buttons_prev[0]) or (state->buttons[1] != state->buttons_prev[1]))
        {

            if ((state->buttons[0] == state->buttons[1]) and (state->buttons[0] == 1))
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
    // Get angles, set forces
    hdGetDoublev(HD_CURRENT_GIMBAL_ANGLES, omni_state->rot);
    hdGetDoublev(HD_CURRENT_POSITION, omni_state->position);
    hdGetDoublev(HD_CURRENT_JOINT_ANGLES, omni_state->joints);

    hduVector3Dd vel_buff(0, 0, 0);
    vel_buff = (omni_state->position * 3 - 4 * omni_state->pos_hist1 + omni_state->pos_hist2) / 0.002;                                                                                                                                      // mm/s, 2nd order backward dif
    omni_state->velocity = (.2196 * (vel_buff + omni_state->inp_vel3) + .6588 * (omni_state->inp_vel1 + omni_state->inp_vel2)) / 1000.0 - (-2.7488 * omni_state->out_vel1 + 2.5282 * omni_state->out_vel2 - 0.7776 * omni_state->out_vel3); // cutoff freq of 20 Hz
    omni_state->pos_hist2 = omni_state->pos_hist1;
    omni_state->pos_hist1 = omni_state->position;
    omni_state->inp_vel3 = omni_state->inp_vel2;
    omni_state->inp_vel2 = omni_state->inp_vel1;
    omni_state->inp_vel1 = vel_buff;
    omni_state->out_vel3 = omni_state->out_vel2;
    omni_state->out_vel2 = omni_state->out_vel1;
    omni_state->out_vel1 = omni_state->velocity;
    if (omni_state->lock == true)
    {
        omni_state->force = 0.04 * (omni_state->lock_pos - omni_state->position) - 0.001 * omni_state->velocity;
    }

    hdSetDoublev(HD_CURRENT_FORCE, omni_state->force);

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
                  omni_state->joints[2] - omni_state->joints[1], omni_state->rot[0],
                  omni_state->rot[1], omni_state->rot[2]};
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
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "HD_CALIBRATION_ENCODER_RESE..");
    }
    if (supportedCalibrationStyles & HD_CALIBRATION_INKWELL)
    {
        calibrationStyle = HD_CALIBRATION_INKWELL;
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "HD_CALIBRATION_INKWELL..");
    }
    if (supportedCalibrationStyles & HD_CALIBRATION_AUTO)
    {
        calibrationStyle = HD_CALIBRATION_AUTO;
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "HD_CALIBRATION_AUTO..");
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
    if (hdCheckCalibration() == HD_CALIBRATION_NEEDS_MANUAL_INPUT)
    {
        RCLCPP_INFO(rclcpp::get_logger("omni_haptic_node"), "Please place the device into the inkwell for calibration.");
    }
}

void *ros_publish(void *ptr)
{
    PhantomROS *omni_ros = (PhantomROS *)ptr;
    int publish_rate = omni_ros->publish_rate;
    rclcpp::Rate loop_rate(publish_rate);

    while (rclcpp::ok())
    {
        omni_ros->publish_omni_state();
        loop_rate.sleep();
    }
    return NULL;
}

int main(int argc, char **argv)
{
    ////////////////////////////////////////////////////////////////
    // Init Phantom
    ////////////////////////////////////////////////////////////////
    HDErrorInfo error;
    HHD hHD;
    hHD = hdInitDevice(DEVICE_NAME);
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

    ////////////////////////////////////////////////////////////////
    // Loop and publish
    ////////////////////////////////////////////////////////////////
    pthread_t publish_thread;
    pthread_create(&publish_thread, NULL, ros_publish, (void *)&omni_ros);
    pthread_join(publish_thread, NULL);

    RCLCPP_INFO(node->get_logger(), "Ending Session....");
    hdStopScheduler();
    hdDisableDevice(hHD);

    return 0;
}
