#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <ctime>

#include "lifecycle_msgs/msg/transition.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/publisher.hpp"
#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"
#include "rcutils/logging_macros.h"

#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "diana_humble/base/dianamed_ctrl.hpp"

using namespace std::chrono_literals;

class TouchXLifecycle : public rclcpp_lifecycle::LifecycleNode
{
public:
    std::shared_ptr<rclcpp::Node> touchx_node_;
    DianaMedBase dianamed_ctrl;
    geometry_msgs::msg::PoseStamped robot_init_pose_;
    geometry_msgs::msg::PoseStamped robot_pose_;
    geometry_msgs::msg::PoseStamped tcp_pose_;
    std_msgs::msg::Float32MultiArray joints_state;
    explicit TouchXLifecycle(const std::string & node_name, bool intra_process_comms = false)
    : rclcpp_lifecycle::LifecycleNode(node_name,rclcpp::NodeOptions().use_intra_process_comms(intra_process_comms)){
        touchx_node_ = rclcpp::Node::make_shared("robotctrl_node");

        init_pose_sub_ = touchx_node_->create_subscription<geometry_msgs::msg::PoseStamped>("/robot_init_pose",
        10, std::bind(&TouchXLifecycle::InitPoseCallback, this, std::placeholders::_1));

        robot_pose_sub_ = touchx_node_->create_subscription<geometry_msgs::msg::PoseStamped>("/robot_pose",
        10, std::bind(&TouchXLifecycle::RobotPoseCallback, this, std::placeholders::_1));
        
        joint_state_pub_ = touchx_node_->create_publisher<std_msgs::msg::Float32MultiArray>("/joints_state_topic", 10);

        tcp_pose_pub_ = touchx_node_->create_publisher<geometry_msgs::msg::PoseStamped>("/tcp_pose", 10);

        joints_state.data = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    }

    void ControlLoop(){
        auto msg = std::make_unique<std_msgs::msg::String>();
        msg->data = "Lifecycle node work !!!!";

        if (!pub_->is_activated()) {
            RCLCPP_INFO(
                get_logger(), "Lifecycle publisher is currently inactive. Messages are not published.");
        } 
        else {
            Eigen::Quaterniond quaternion(robot_pose_.pose.orientation.w,
                                          robot_pose_.pose.orientation.x,                                      
                                          robot_pose_.pose.orientation.y,
                                          robot_pose_.pose.orientation.z);

            Eigen::Matrix3d rotation_matrix = quaternion.normalized().toRotationMatrix();

            dianamed_ctrl.p_init.p = KDL::Vector(robot_pose_.pose.position.x, robot_pose_.pose.position.y, robot_pose_.pose.position.z);
            dianamed_ctrl.p_init.M = KDL::Rotation(rotation_matrix.data()[0],rotation_matrix.data()[1],rotation_matrix.data()[2],
                                              rotation_matrix.data()[3],rotation_matrix.data()[4],rotation_matrix.data()[5],
                                              rotation_matrix.data()[6],rotation_matrix.data()[7],rotation_matrix.data()[8]);
            dianamed_ctrl.Piksolver->CartToJnt(dianamed_ctrl.q_init, dianamed_ctrl.p_init, dianamed_ctrl.q_goal);

            for(int i = 0; i < 7; i++){
                dianamed_ctrl.joints[i] = dianamed_ctrl.q_goal(i);
                dianamed_ctrl.q_init(i) = dianamed_ctrl.q_goal(i);
                std::cout << dianamed_ctrl.joints[i] << " ";
            }
            std::cout << std::endl;
            // 极限状态下的参数
            // int ret = servoJ_ex(dianamed_ctrl.joints, 0.005, 0.025, 800, false, dianamed_ctrl.DianaMedIpAddress);
            int ret = servoJ_ex(dianamed_ctrl.joints, 0.01, 0.04, 500, false, dianamed_ctrl.DianaMedIpAddress);
            // std::cout <<"servoJ state:(0/-1)"<<ret<<std::endl;
            joints_state.data = {
                dianamed_ctrl.joints[0],
                dianamed_ctrl.joints[1],
                dianamed_ctrl.joints[2],
                dianamed_ctrl.joints[3],
                dianamed_ctrl.joints[4],
                dianamed_ctrl.joints[5],
                dianamed_ctrl.joints[6]
            };
            joint_state_pub_->publish(joints_state);
            

            double poses[6];
            dianamed_ctrl.getTCPpose(poses);

            tcp_pose_.pose.position.x = poses[0];
            tcp_pose_.pose.position.y = poses[1];
            tcp_pose_.pose.position.z = poses[2];

            tcp_pose_pub_->publish(tcp_pose_);
            // RCLCPP_INFO(
            //     get_logger(), "Lifecycle publisher is active. Publishing: [%s]", msg->data.c_str()); 
        }
        // pub_->publish(std::move(msg));
    }

    void wait_move(const char* strIpAddress){
        usleep(20000);
        while (true){
            const char state = getRobotState(strIpAddress);
            if (state != 0){
                break;
            }
            else{
                 usleep(1000);
            }
        }
        stop(strIpAddress);
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
    on_configure(const rclcpp_lifecycle::State &){
        RCLCPP_INFO(get_logger(), "on_configure() is called.");

        pub_ = this->create_publisher<std_msgs::msg::String>("lifecycle_chatter", 10);
        timer_ = this->create_wall_timer(
        1ms, std::bind(&TouchXLifecycle::ControlLoop, this));

        Eigen::Quaterniond quaternion(robot_init_pose_.pose.orientation.w,
                                      robot_init_pose_.pose.orientation.x,                                      
                                      robot_init_pose_.pose.orientation.y,
                                      robot_init_pose_.pose.orientation.z);

        Eigen::Matrix3d rotation_matrix = quaternion.normalized().toRotationMatrix();

        double matrix[16]={ rotation_matrix.data()[0], rotation_matrix.data()[3], rotation_matrix.data()[6], 0.000000, 
                            rotation_matrix.data()[1], rotation_matrix.data()[4], rotation_matrix.data()[7], 0.000000, 
                            rotation_matrix.data()[2], rotation_matrix.data()[5], rotation_matrix.data()[8], 0.000000, 
                            robot_init_pose_.pose.position.x, robot_init_pose_.pose.position.y, robot_init_pose_.pose.position.z, 1.000000};
        
        double pose[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        
        homogeneous2Pose(matrix, pose);
        
        for (int i = 0 ;i < 7;i++){
            std::cout<< pose[i]<<" ";
        }
        std::cout << std::endl;
        
        double joints[7] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

        int ret = inverse(pose, joints, nullptr,dianamed_ctrl.DianaMedIpAddress);
        std::cout <<"inverse state:"<<ret<<std::endl;

        for(int i = 0; i < 7; i++){
            dianamed_ctrl.q_init(i) = joints[i];
            std::cout << joints[i] << " ";
        }
        std::cout << "\n";

        // robot move to init pose
        double vel = 0.5;
        double acc = 0.5;
        moveJ(joints, vel, acc, dianamed_ctrl.DianaMedIpAddress);
        wait_move(dianamed_ctrl.DianaMedIpAddress);

        RCLCPP_INFO(get_logger(), "on_configure() is finished.");

        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
    on_activate(const rclcpp_lifecycle::State &){
        pub_->on_activate();
        RCUTILS_LOG_INFO_NAMED(get_name(), "on_activate() is called.");
        std::this_thread::sleep_for(2s);
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
    on_deactivate(const rclcpp_lifecycle::State &){
        pub_->on_deactivate();
        RCUTILS_LOG_INFO_NAMED(get_name(), "on_deactivate() is called.");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
    on_cleanup(const rclcpp_lifecycle::State &){
        timer_.reset();
        pub_.reset();
        RCUTILS_LOG_INFO_NAMED(get_name(), "on cleanup is called.");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
    on_shutdown(const rclcpp_lifecycle::State & state){
        timer_.reset();
        pub_.reset();
        RCUTILS_LOG_INFO_NAMED(
        get_name(),
        "on shutdown is called from state %s.",
        state.label().c_str());
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

private:
    std::shared_ptr<rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>> pub_;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Float32MultiArray>> joint_state_pub_;
    std::shared_ptr<rclcpp::Subscription<geometry_msgs::msg::PoseStamped>> init_pose_sub_;
    std::shared_ptr<rclcpp::Subscription<geometry_msgs::msg::PoseStamped>> robot_pose_sub_;
    std::shared_ptr<rclcpp::Publisher<geometry_msgs::msg::PoseStamped>> tcp_pose_pub_;

    std::shared_ptr<rclcpp::TimerBase> timer_;

    void InitPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg){
        robot_init_pose_.pose = msg->pose;
    }

    void RobotPoseCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg){
        robot_pose_.pose = msg->pose;
    }

};

void logRobotState(StrRobotStateInfo *pinfo){
}

void errorControl(int e){
    const char * strError = formatError(e); 
    printf("error code (%d):%s\n", e, strError);
}

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor executor;

    std::shared_ptr<TouchXLifecycle> touchx_lifecycle_node = std::make_shared<TouchXLifecycle>("touchx_lifecycle_node");

    initSrv(nullptr,nullptr,touchx_lifecycle_node->dianamed_ctrl.pInfo);
    releaseBrake (touchx_lifecycle_node->dianamed_ctrl.DianaMedIpAddress); 

    auto pose_sub_node = touchx_lifecycle_node->touchx_node_;
    executor.add_node(touchx_lifecycle_node->get_node_base_interface());
    executor.add_node(pose_sub_node);
    executor.spin();

    holdBrake (touchx_lifecycle_node->dianamed_ctrl.DianaMedIpAddress);  
    destroySrv (touchx_lifecycle_node->dianamed_ctrl.DianaMedIpAddress);
    
    rclcpp::shutdown();
    return 0;
}
