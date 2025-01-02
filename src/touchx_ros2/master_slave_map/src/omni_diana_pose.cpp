#include <Eigen/Core>
#include <Eigen/Eigen>
#include <Eigen/Geometry>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include <builtin_interfaces/msg/time.hpp>

class RobotPoseNode
{
public:
    std::shared_ptr<rclcpp::Node> node;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr touchx_pose_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr robot_init_pose_publisher_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr robot_pose_publisher_;

    Eigen::Vector3d robot_init_pose; // m robot init pose 
    Eigen::Vector3d touch_init_pose;// m touchx init pose

    Eigen::Vector3d touch_min_xyz; // m touch min xyz
    Eigen::Vector3d touch_max_xyz; // m touch max xyz
    
    Eigen::Vector3d robot_min_xyz; // m robot min xyz
    Eigen::Vector3d robot_max_xyz; // m robot max xyz

    Eigen::Matrix3d sMatrix;    // coefficient matrix
    Eigen::Vector3d robot_pose; // for robot pose

    geometry_msgs::msg::PoseStamped robot_pose_msg; // robot pose msg
    geometry_msgs::msg::PoseStamped robot_init_pose_msg;

    Eigen::Matrix3d rotation_matrix;

    int count = 0; 

    RobotPoseNode();

private:

    void Pose_Callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);

};


RobotPoseNode::RobotPoseNode(){
    node = rclcpp::Node::make_shared("robot_pose_node");
    touchx_pose_subscription_ = node->create_subscription<geometry_msgs::msg::PoseStamped>("/phantom/pose",
        10, std::bind(&RobotPoseNode::Pose_Callback, this, std::placeholders::_1));
    robot_init_pose_publisher_ = node->create_publisher<geometry_msgs::msg::PoseStamped>("/robot_init_pose",10);
    robot_pose_publisher_ = node->create_publisher<geometry_msgs::msg::PoseStamped>("/robot_pose",10);

    // touch_min_xyz = Eigen::Vector3d(-0.2,-0.09,-0.11);
    // touch_max_xyz = Eigen::Vector3d(0.2, 0.08, 0.19);
    touch_min_xyz = Eigen::Vector3d(-0.2,-0.08,-0.10);
    touch_max_xyz = Eigen::Vector3d(0.2, 0.08, 0.18);

    robot_min_xyz = Eigen::Vector3d(0.4, -0.12 , 0.13);
    robot_max_xyz = Eigen::Vector3d(1, 0.12, 0.5);
    // robot_min_xyz = Eigen::Vector3d(0.45, -0.12 , 0.13);
    // robot_max_xyz = Eigen::Vector3d(0.9, 0.12, 0.5);

    rotation_matrix = Eigen::AngleAxisd(M_PI/7, Eigen::Vector3d(0, 1, 0));
    RCLCPP_INFO(node->get_logger(), "robot_pose_node init!");

}

void RobotPoseNode::Pose_Callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg){   
    if(count < 100){
        touch_init_pose.x() = -msg->pose.position.y;
        touch_init_pose.y() = -msg->pose.position.x;
        touch_init_pose.z() = msg->pose.position.z;
        Eigen::Vector3d touch_robot_abs_;
        Eigen::Vector3d touch_robot_x;
        for (int i = 0; i < 3; i++){
            touch_robot_abs_.data()[i] = abs(touch_init_pose.data()[i] - touch_min_xyz.data()[i]) / (touch_max_xyz.data()[i] - touch_min_xyz.data()[i]);
            touch_robot_x.data()[i] =   touch_robot_abs_.data()[i] * (robot_max_xyz.data()[i] - robot_min_xyz.data()[i]);
        }

        robot_init_pose = robot_min_xyz + touch_robot_x;

        Eigen::Vector3d s;

        for(int i = 0; i < 3; i++){
            s.data()[i] = (robot_max_xyz.data()[i] - robot_init_pose.data()[i])  / (touch_max_xyz.data()[i] - touch_init_pose.data()[i]);
        }
        sMatrix << s.x(), 0, 0,
                    0, s.y(), 0,
                    0, 0, s.z();
        robot_init_pose_msg.header = msg->header;
        robot_init_pose_msg.pose.position.x = robot_init_pose.x();
        robot_init_pose_msg.pose.position.y = robot_init_pose.y();
        robot_init_pose_msg.pose.position.z = robot_init_pose.z();

        Eigen::Quaterniond quaternion(msg->pose.orientation.w,
                                      msg->pose.orientation.x,                                      
                                      msg->pose.orientation.y,
                                      msg->pose.orientation.z);

        Eigen::Matrix3d touchx_rotation_matrix = quaternion.normalized().toRotationMatrix();

        Eigen::Matrix3d after_rotation = touchx_rotation_matrix * rotation_matrix;

        Eigen::Quaterniond after_rotation_quaterniond(after_rotation);

        robot_init_pose_msg.pose.orientation.x = after_rotation_quaterniond.x();
        robot_init_pose_msg.pose.orientation.y = after_rotation_quaterniond.y();
        robot_init_pose_msg.pose.orientation.z = after_rotation_quaterniond.z();
        robot_init_pose_msg.pose.orientation.w = after_rotation_quaterniond.w();

        count++;    
    }else{
        Eigen::Vector3d deltaP;
        deltaP.x() = -msg->pose.position.y - touch_init_pose.x();
        deltaP.y() = -msg->pose.position.x - touch_init_pose.y();
        deltaP.z() = msg->pose.position.z - touch_init_pose.z();

        robot_pose = sMatrix * deltaP + robot_init_pose;

        robot_pose_msg.header = msg->header;
        robot_pose_msg.pose.position.x = robot_pose.x();
        robot_pose_msg.pose.position.y = robot_pose.y();
        robot_pose_msg.pose.position.z = robot_pose.z();

        Eigen::Quaterniond quaternion(msg->pose.orientation.w,
                                      msg->pose.orientation.x,                                      
                                      msg->pose.orientation.y,
                                      msg->pose.orientation.z);

        Eigen::Matrix3d touchx_rotation_matrix = quaternion.normalized().toRotationMatrix();

        Eigen::Matrix3d after_rotation = touchx_rotation_matrix * rotation_matrix;

        Eigen::Quaterniond after_rotation_quaterniond(after_rotation);


        robot_pose_msg.pose.orientation.x = after_rotation_quaterniond.x();
        robot_pose_msg.pose.orientation.y = after_rotation_quaterniond.y();
        robot_pose_msg.pose.orientation.z = after_rotation_quaterniond.z();
        robot_pose_msg.pose.orientation.w = after_rotation_quaterniond.w();
        
        robot_pose_publisher_->publish(robot_pose_msg);
    }
    robot_init_pose_publisher_->publish(robot_init_pose_msg);
}


int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto robot_pose = std::make_shared<RobotPoseNode>();
    auto robot_pose_node = robot_pose->node;
    rclcpp::spin(robot_pose_node);
    rclcpp::shutdown();
    return 0;
}