#include <Eigen/Core>
#include <Eigen/Eigen>
#include <Eigen/Geometry>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

#include <builtin_interfaces/msg/time.hpp>

class MapPoseNode{
public:
    std::shared_ptr<rclcpp::Node> map_pose_node;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr Touch_pose_subscription;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr Dianamed_init_pose_publisher;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr Dianamed_pose_publisher;

    Eigen::Vector3d Dianamed_init_pose;
    Eigen::Vector3d Touch_init_pose;
    Eigen::Vector3d Dianamed_pose;
    Eigen::Vector3d Touch_xyz_min;
    Eigen::Vector3d Touch_xyz_max;
    Eigen::Vector3d Dianamed_xyz_min;
    Eigen::Vector3d Dianamed_xyz_max;

    Eigen::Matrix3d tmp_Matrix;
    Eigen::Matrix3d rotation_matrix;

    geometry_msgs::msg::PoseStamped Dianamed_init_pose_msg;
    geometry_msgs::msg::PoseStamped Dianamed_pose_msg;

    MapPoseNode();

private:
    void Pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
    int count = 0;
};

MapPoseNode::MapPoseNode(){
    map_pose_node = rclcpp::Node::make_shared("robot_pose_node");
    Touch_pose_subscription = map_pose_node->create_subscription<geometry_msgs::msg::PoseStamped>("/phantom/pose", 10, 
    std::bind(&MapPoseNode::Pose_callback, this, std::placeholders::_1));
    Dianamed_init_pose_publisher = map_pose_node->create_publisher<geometry_msgs::msg::PoseStamped>("/robot_init_pose", 10);
    Dianamed_pose_publisher = map_pose_node->create_publisher<geometry_msgs::msg::PoseStamped>("/robot_pose", 10);

    Touch_xyz_min = Eigen::Vector3d(-0.2,-0.094,-0.11);
    Touch_xyz_max = Eigen::Vector3d(0.2, 0.1, 0.19);

    Dianamed_xyz_min = Eigen::Vector3d(0.4, -0.12, 0.13);
    Dianamed_xyz_max = Eigen::Vector3d(0.8, 0.12, 0.5);

    RCLCPP_INFO(map_pose_node->get_logger(), "robot_pose_node init!");
}

void MapPoseNode::Pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg){
    if(count < 100){
        Touch_init_pose.x() = msg->pose.position.y;
        Touch_init_pose.y() = msg->pose.position.x;
        Touch_init_pose.z() = msg->pose.position.z;
        
        Eigen::Vector3d Touch_robot_abs;
        Eigen::Vector3d touch_robot_x;

        for(int i = 0;i < 3;i++){
            Touch_robot_abs.data()[i] = abs(Touch_init_pose.data()[i] - Touch_xyz_min.data()[i])/(Touch_xyz_max.data()[i] - Touch_xyz_min.data()[i]);
            touch_robot_x.data()[i] = Touch_robot_abs.data()[i] * (Dianamed_xyz_max.data()[i] - Dianamed_xyz_min.data()[i]);
        }

        Dianamed_init_pose = Dianamed_xyz_min + touch_robot_x;

        Eigen::Vector3d s;

        for(int i = 0; i<3; i++){
            s.data()[i] = (Dianamed_xyz_max.data()[i] - Dianamed_init_pose.data()[i]) / (Touch_xyz_max.data()[i] - Touch_xyz_min.data()[i]);
        }

        tmp_Matrix << s.x(), 0, 0,
                      0, s.y(), 0,
                      0, 0, s.z();

        Dianamed_init_pose_msg.header = msg->header;
        Dianamed_init_pose_msg.pose.position.x = Dianamed_init_pose.x();
        Dianamed_init_pose_msg.pose.position.y = Dianamed_init_pose.y();
        Dianamed_init_pose_msg.pose.position.z = Dianamed_init_pose.z();

        Eigen::Quaterniond quaternion(msg->pose.orientation.w,
                                      msg->pose.orientation.x,                                      
                                      msg->pose.orientation.y,
                                      msg->pose.orientation.z);

        Eigen::Matrix3d touch_rotation_matrix = quaternion.normalized().toRotationMatrix();
        Eigen::Matrix3d after_rotation = touch_rotation_matrix * rotation_matrix;
        Eigen::Quaterniond after_rotation_quaterniond(after_rotation);

        Dianamed_init_pose_msg.pose.orientation.x = after_rotation_quaterniond.x();
        Dianamed_init_pose_msg.pose.orientation.y = after_rotation_quaterniond.y();
        Dianamed_init_pose_msg.pose.orientation.z = after_rotation_quaterniond.z();
        Dianamed_init_pose_msg.pose.orientation.w = after_rotation_quaterniond.w();

        count++;  
    }
    else{
        Eigen::Vector3d deltaP;
    }
}