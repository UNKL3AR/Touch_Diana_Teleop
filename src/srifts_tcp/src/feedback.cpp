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
        // subscription_ = this->create_subscription<sri_interface::msg::SixAxisFTS>(
        //     "/M3733C_Force_Sensor", 10,
        //     std::bind(&FeedbackConverterNode::raw_data_callback, this, std::placeholders::_1));

        subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/Force", 1000,
            std::bind(&FeedbackConverterNode::raw_data_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<omni_msgs::msg::OmniFeedback>("/phantom/force_feedback", 1000);

        timer_ = this->create_wall_timer(std::chrono::milliseconds(timerIntervalMs),
                                         std::bind(&FeedbackConverterNode::publish_mean_filtered_force, this));

        // x_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
        // y_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
        // z_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
    }

private:
    // void updateFilteredForce(double& filteredForce, std::shared_ptr<KalmanFilter>& filter, double newValue) {
        // filteredForce = filter->update(newValue);
    // }

    // void raw_data_callback(const sri_interface::msg::SixAxisFTS::SharedPtr data) {
    void raw_data_callback(const geometry_msgs::msg::Twist::SharedPtr data){
        // updateFilteredForce(filtered_x_force, x_kalman, data->x_force);
        // updateFilteredForce(filtered_y_force, y_kalman, data->y_force);
        // updateFilteredForce(filtered_z_force, z_kalman, data->z_force);

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

    // std::shared_ptr<KalmanFilter> x_kalman;
    // std::shared_ptr<KalmanFilter> y_kalman;
    // std::shared_ptr<KalmanFilter> z_kalman;

    // rclcpp::Subscription<sri_interface::msg::SixAxisFTS>::SharedPtr subscription_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
    rclcpp::Publisher<omni_msgs::msg::OmniFeedback>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    
    // double filtered_x_force = 0.0;
    // double filtered_y_force = 0.0;
    // double filtered_z_force = 0.0;

    double x_init = 0;
    double y_init = 0;
    double z_init = 0;

    double data_x = 0;
    double data_y = 0;
    double data_z = 0;

    // double gain_x = 0.07;
    // double gain_y = 0.07;
    // double gain_z = 0.07;

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

// #include <chrono>
// #include <functional>
// #include <memory>
// #include <string>
// #include <vector>
// #include "rclcpp/rclcpp.hpp"
// #include <std_msgs/msg/float32.hpp>
// #include <geometry_msgs/msg/twist.hpp>
// #include "omni_msgs/msg/omni_feedback.hpp"

// using std::placeholders::_1;

// class FeedbackConverterNode : public rclcpp::Node {
// public:
//     FeedbackConverterNode() : Node("feedback_converter_node"), initialized(false), count(0) {
//         subscription_ = this->create_subscription<geometry_msgs::msg::Twist>(
//             "/Force", 10,
//             std::bind(&FeedbackConverterNode::raw_data_callback, this, _1));

//         publisher_ = this->create_publisher<omni_msgs::msg::OmniFeedback>("/phantom/force_feedback", 10);

//         timer_ = this->create_wall_timer(std::chrono::milliseconds(timerIntervalMs),
//                                          std::bind(&FeedbackConverterNode::publish_mean_filtered_force, this));

//         // Initialize gains and initial values
//         this->declare_parameter<double>("gain_x", 10.0);
//         this->declare_parameter<double>("gain_y", 10.0);
//         this->declare_parameter<double>("gain_z", 10.0);
//         this->get_parameter("gain_x", gain_x);
//         this->get_parameter("gain_y", gain_y);
//         this->get_parameter("gain_z", gain_z);
//     }

// private:
//     void raw_data_callback(const geometry_msgs::msg::Twist::SharedPtr data) {
//         if (!initialized) {
//             x_init = data->linear.x;
//             y_init = data->linear.y;
//             z_init = data->linear.z;
//             initialized = true;
//         }

//         data_x = data->linear.x;
//         data_y = data->linear.y;
//         data_z = data->linear.z;

//         force_msg.force.x = -(data_x - x_init) * gain_x;
//         force_msg.force.y = (data_y - y_init) * gain_y;
//         force_msg.force.z = -(data_z - z_init) * gain_z;

//         RCLCPP_DEBUG(this->get_logger(), "Raw data: x=%f, y=%f, z=%f", data_x, data_y, data_z);
//         RCLCPP_DEBUG(this->get_logger(), "Force: x=%f, y=%f, z=%f", force_msg.force.x, force_msg.force.y, force_msg.force.z);
//     }

//     void publish_mean_filtered_force() {
//         if (publisher_->get_subscription_count() > 0) {
//             publisher_->publish(force_msg);
//         } else {
//             RCLCPP_WARN(this->get_logger(), "No subscribers for force feedback topic");
//         }
//         RCLCPP_INFO(this->get_logger(), "Publish count: %d", count++);
//     }

//     const int timerIntervalMs = 10;

//     omni_msgs::msg::OmniFeedback force_msg;
//     rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
//     rclcpp::Publisher<omni_msgs::msg::OmniFeedback>::SharedPtr publisher_;
//     rclcpp::TimerBase::SharedPtr timer_;

//     double x_init, y_init, z_init;
//     double data_x, data_y, data_z;
//     double gain_x, gain_y, gain_z;

//     int count;
//     bool initialized;
// };

// int main(int argc, char *argv[]) {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<FeedbackConverterNode>();
//     if (node) {
//         rclcpp::spin(node);
//     } else {
//         RCLCPP_ERROR(rclcpp::get_logger("main"), "Failed to create node");
//     }
//     rclcpp::shutdown();
//     return 0;
// }
