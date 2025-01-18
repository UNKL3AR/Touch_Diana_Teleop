#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/float32.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "omni_msgs/msg/omni_feedback.hpp"

using std::placeholders::_1;

class FeedbackConverterNode : public rclcpp::Node {
public:
    FeedbackConverterNode() : Node("feedback_converter_node") {
       
        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/Force", 1000,
            std::bind(&FeedbackConverterNode::raw_data_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<omni_msgs::msg::OmniFeedback>("/phantom/force_feedback", 1000);

        timer_ = this->create_wall_timer(std::chrono::milliseconds(timerIntervalMs),
                                         std::bind(&FeedbackConverterNode::publish_mean_filtered_force, this));
    }

private:
    void raw_data_callback(const geometry_msgs::msg::Twist::SharedPtr data){
        if (!initialized) {
            x_init = data->linear.x;
            y_init = data->linear.y;
            z_init = data->linear.z;
            initialized = true;
        }

        data_x = data->linear.x;
        data_y = data->linear.y;
        data_z = data->linear.z;

        force_msg.force.x = -(data_x - x_init)*gain_x;
        force_msg.force.y = (data_y - y_init)*gain_y;
        force_msg.force.z = -(data_z - z_init)*gain_z;
    }

    void publish_mean_filtered_force() {
        if (publisher_ && publisher_->get_subscription_count() > 0) {
            publisher_->publish(force_msg); 
        } else {
            RCLCPP_ERROR(this->get_logger(), "No subscribers for force feedback topic");
        }
        RCLCPP_INFO(this->get_logger(), "Count: %d", count++);
    }

    const int timerIntervalMs = 10;

    omni_msgs::msg::OmniFeedback force_msg;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<omni_msgs::msg::OmniFeedback>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    double x_init = 0;
    double y_init = 0;
    double z_init = 0;

    double data_x = 0;
    double data_y = 0;
    double data_z = 0;

    double gain_x = 6;
    double gain_y = 6;
    double gain_z = 6;

    int count = 0;
    bool initialized = false;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<FeedbackConverterNode>();
    if (node) {
        rclcpp::spin(node);
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("main"), "Failed to create node");
    }
    rclcpp::shutdown();
    return 0;
}
