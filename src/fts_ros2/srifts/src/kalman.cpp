#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/float32.hpp>
#include "sri_interface/msg/six_axis_fts.hpp"
#include "omni_msgs/msg/omni_feedback.hpp"

using std::placeholders::_1;

// Kalman Filter class for a single axis
class KalmanFilter {
public:
    KalmanFilter(double initial_state, double initial_estimate_error, double process_noise, double measurement_noise)
        : state_estimate(initial_state), estimate_error(initial_estimate_error),
          Q(process_noise), R(measurement_noise) {}

    double update(double measurement) {
        // Prediction
        double predicted_estimate = state_estimate;
        double predicted_error = estimate_error + Q;

        // Update
        double kalman_gain = predicted_error / (predicted_error + R);
        state_estimate = predicted_estimate + kalman_gain * (measurement - predicted_estimate);
        estimate_error = (1 - kalman_gain) * predicted_error;

        return state_estimate;
    }

private:
    double state_estimate;   // Current state estimate
    double estimate_error;   // Current estimate error
    double Q;                // Process noise
    double R;                // Measurement noise
};

class FeedbackConverterNode : public rclcpp::Node {
public:
    FeedbackConverterNode() : Node("feedback_converter_node") {
        subscription_ = this->create_subscription<sri_interface::msg::SixAxisFTS>(
            "/M3733C_Force_Sensor", 10,
            std::bind(&FeedbackConverterNode::raw_data_callback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<omni_msgs::msg::OmniFeedback>("/phantom/force_feedback", 10);

        timer_ = this->create_wall_timer(std::chrono::milliseconds(timerIntervalMs),
                                         std::bind(&FeedbackConverterNode::publish_mean_filtered_force, this));

        x_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
        y_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
        z_kalman = std::make_shared<KalmanFilter>(initial_state, initial_estimate_error, process_noise, measurement_noise);
    }

private:
    void updateFilteredForce(double& filteredForce, std::shared_ptr<KalmanFilter>& filter, double newValue) {
        filteredForce = filter->update(newValue);
    }

    void raw_data_callback(const sri_interface::msg::SixAxisFTS::SharedPtr data) {
        updateFilteredForce(filtered_x_force, x_kalman, data->x_force);
        updateFilteredForce(filtered_y_force, y_kalman, data->y_force);
        updateFilteredForce(filtered_z_force, z_kalman, data->z_force);

        if (!initialized) {
            x_init = filtered_x_force;
            y_init = filtered_y_force;
            z_init = filtered_z_force;
            initialized = true;
        }

        force_msg.force.x = -(filtered_x_force - x_init)*gain_x;
        force_msg.force.y = (filtered_y_force - y_init)*gain_y;
        force_msg.force.z = -(filtered_z_force - z_init)*gain_z;
    }

    void publish_mean_filtered_force() {
        if (publisher_ && publisher_->get_subscription_count() > 0) {
            publisher_->publish(force_msg); 
        } else {
            RCLCPP_ERROR(this->get_logger(), "No subscribers for force feedback topic");
        }
        RCLCPP_INFO(this->get_logger(), "Count: %d", count++);
    }

    const int timerIntervalMs = 1;

    omni_msgs::msg::OmniFeedback force_msg;

    std::shared_ptr<KalmanFilter> x_kalman;
    std::shared_ptr<KalmanFilter> y_kalman;
    std::shared_ptr<KalmanFilter> z_kalman;

    rclcpp::Subscription<sri_interface::msg::SixAxisFTS>::SharedPtr subscription_;
    rclcpp::Publisher<omni_msgs::msg::OmniFeedback>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    
    double filtered_x_force = 0.0;
    double filtered_y_force = 0.0;
    double filtered_z_force = 0.0;

    double x_init = 0;
    double y_init = 0;
    double z_init = 0;

    double gain_x = 0.07;
    double gain_y = 0.07;
    double gain_z = 0.07;

    int count = 0;
    bool initialized = false;

    // Kalman filter parameters
    double initial_state = 0.0;         // Initial state estimate
    double initial_estimate_error = 1.0; // Initial estimate error
    double process_noise = 0.01;         // Process noise covariance
    double measurement_noise = 0.1;      // Measurement noise covariance
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
