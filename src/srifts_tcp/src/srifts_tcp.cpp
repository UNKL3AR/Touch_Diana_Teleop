// #include <rclcpp/rclcpp.hpp>
// #include <std_msgs/msg/string.hpp>
// #include <geometry_msgs/msg/twist.hpp>
// #include <signal.h>
// #include "TCP_sock.hpp"

// #define M812X_CHN_NUMBER	6


// // class ForceSensorPublisher : public rclcpp::Node {
// // public:
// //     static void sig_exit(int s){
// //         // Handle SIGINT gracefully
// //         RCLCPP_INFO(this->get_logger(), "Shutting down...");
// //         rclcpp::shutdown();
// //     }

// //     bool ConfigSystem(void){
// //     _tcp.Send("AT+SGDM=(A01,A02,A03,A04,A05,A06);C;1;(WMA:1)\r\n");
// //     std::string rec = _tcp.read();
// //     if( rec != "" )
// //     {
// //         std::cout << "Server Response:" << rec << std::endl;
// //     } else
// //     {
// //         std::cout << "Server Not Response:"  << std::endl;
// //     }

// //     _tcp.Send("AT+AMPZ=?\r\n");
// //     if(_tcp.GetChParameter(m_dAmpZero))
// //     {
// //         std::cout << "AT+AMPZ=: " << m_dAmpZero << std::endl;
// //     }else{
// //         std::cout << "Server no Response:" << std::endl;
// //     }

// //     _tcp.Send("AT+CHNAPG=?\r\n");
// //     if(_tcp.GetChParameter(m_dChnGain))
// //     {
// //         std::cout << "AT+CHNAPG=: " << m_dChnGain << std::endl;
// //     }else{
// //         std::cout << "Server no Response:" << std::endl;
// //     }
// //     _tcp.Send("AT+GOD\r\n");
// //     if(_tcp.GetADCounts(m_nADCounts))
// //     {
// //         std::cout << "AD value:" << m_nADCounts << std::endl;
// //     }else{
// //         std::cout << "Server no Response:" << std::endl;
// //     }

// //     for (unsigned  int i = 0; i < 6; ++i) {
// //         m_dResultChValue(i) = 1000*( (m_nADCounts(i) - m_dAmpZero(i)) / (double)65535*(double)5 ) / m_dChnGain(i);
// //     }
// //     std::cout << "result value is : "  <<m_dResultChValue << std::endl;

// //     m_dDecouplingCoefficient<<0.000130,0.051905,0.000135,-0.052493,0.000118,0.000096,
// //                                 0.000027,0.030204,0.000105,0.030377,0.000030,-0.060715,
// //                             0.047253,-0.000245,0.048106,-0.001334,0.048817,-0.000172,
// //                             0.001345,-0.000001,-0.001430,0.000056,-0.000031,-0.000024,
// //                             0.000785,-0.000040,0.000793,0.000016,-0.001608,0.000009,
// //                             -0.000004,-0.001925,0.000002,-0.001920,0.000002,-0.001960;
// //     std::cout << "Decoupling matrix is set as: " <<std::endl <<m_dDecouplingCoefficient << std::endl;
// //     m_dDecouplingValue=m_dResultChValue*m_dDecouplingCoefficient.transpose();
// //     std::cout << "force is: " <<std::endl <<m_dDecouplingValue << std::endl;
// //     return true;
// //     }


// //     ForceSensorPublisher()
// //         : Node("force_sensor_publisher"), count_(0) {
// //         // Setup publisher
// //         publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("Force", 1000);
// //         timer_ = this->create_wall_timer(
// //             std::chrono::milliseconds(1),
// //             std::bind(&ForceSensorPublisher::timer_callback, this)
// //         );

// //         // Setup signal handler for graceful shutdown
// //         std::signal(SIGINT, ForceSensorPublisher::sig_exit);

// //         // Setup TCP connection
// //         if (_tcp.setup("192.168.0.108", 4008) == true) {
// //             RCLCPP_INFO(this->get_logger(), "Force sensor has been connected!");
// //         } else {
// //             RCLCPP_ERROR(this->get_logger(), "Force sensor connection failed!");
// //         }

// //         // Initialize the force sensor settings
// //         ConfigSystem();
// //         _tcp.Send("AT+GSD\r\n");
// //     }

// // private:
// //     TCPClient _tcp;
// //     Eigen::MatrixXd m_dResultChValue=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER);   //engineering output of each channel
// //     Eigen::MatrixXd m_dDecouplingValue=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER); //final output
// //     Eigen::MatrixXd m_nADCounts=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER);        //ad output
// //     Eigen::MatrixXd m_dAmpZero=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER);         //read
// //     Eigen::MatrixXd m_dChnGain=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER);         //read
// //     Eigen::MatrixXd m_dChnEx=Eigen::MatrixXd::Zero(1,M812X_CHN_NUMBER);           //read
// //     Eigen::MatrixXd m_dDecouplingCoefficient=Eigen::MatrixXd::Zero(M812X_CHN_NUMBER, M812X_CHN_NUMBER);

// //     void timer_callback() {
// //         _tcp.readrecieveBuffer(m_nADCounts);
// //         for (unsigned int i = 0; i < 6; ++i) {
// //             m_dResultChValue(i) = 1000 * ((m_nADCounts(i) - m_dAmpZero(i)) / 65535.0 * 5.0) / m_dChnGain(i);
// //         }
// //         m_dDecouplingValue = m_dResultChValue * m_dDecouplingCoefficient.transpose();
// //         std::cout << "force is: " << std::endl << m_dDecouplingValue << std::endl;

// //         auto message = geometry_msgs::msg::Twist();
// //         message.linear.x = m_dDecouplingValue(0,0);
// //         message.linear.y = m_dDecouplingValue(0,1);
// //         message.linear.z = m_dDecouplingValue(0,2);
// //         message.angular.x = m_dDecouplingValue(0,3);
// //         message.angular.y = m_dDecouplingValue(0,4);
// //         message.angular.z = m_dDecouplingValue(0,5);

// //         publisher_->publish(message);
// //         ++count_;
// //     }


// //     rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
// //     rclcpp::TimerBase::SharedPtr timer_;
// //     int count_;
// // };

// class ForceSensorPublisher : public rclcpp::Node {
// public:
//     ForceSensorPublisher() : Node("force_sensor_publisher"), count_(0) {
//         // Setup publisher
//         publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("Force", 1000);
//         timer_ = this->create_wall_timer(std::chrono::milliseconds(1), std::bind(&ForceSensorPublisher::timer_callback, this));

//         // Setup signal handler for graceful shutdown
//         std::signal(SIGINT, ForceSensorPublisher::sig_exit);

//         // Setup TCP connection
//         if (!setupTCP()) {
//             RCLCPP_ERROR(this->get_logger(), "Force sensor connection failed!");
//             return;
//         }
//         RCLCPP_INFO(this->get_logger(), "Force sensor has been connected!");

//         // Initialize the force sensor settings
//         if (!configSystem()) {
//             RCLCPP_ERROR(this->get_logger(), "Failed to configure force sensor!");
//         }
//     }

// private:
//     rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
//     rclcpp::TimerBase::SharedPtr timer_;
//     int count_;
//     TCPClient _tcp;

//     static void sig_exit(int s){
//         // Handle SIGINT gracefully
//         // RCLCPP_INFO(this->get_logger(), "Shutting down...");
//         rclcpp::shutdown();
//     }   

//     bool setupTCP() {
//         return _tcp.setup("192.168.0.108", 4008);
//     }

//     bool configSystem() {
//         if (!sendCommandAndGetResponse("AT+SGDM=(A01,A02,A03,A04,A05,A06);C;1;(WMA:1)\r\n", "Server Response:")) return false;
//         if (!getAndPrintParameter("AT+AMPZ=?", m_dAmpZero, "AT+AMPZ=: ")) return false;
//         if (!getAndPrintParameter("AT+CHNAPG=?", m_dChnGain, "AT+CHNAPG=: ")) return false;
//         if (!getAndPrintADCounts()) return false;

//         // Initialize decoupling coefficient matrix
//         m_dDecouplingCoefficient << 0.000130, 0.051905, 0.000135, -0.052493, 0.000118, 0.000096,
//                                     0.000027, 0.030204, 0.000105, 0.030377, 0.000030, -0.060715,
//                                     0.047253, -0.000245, 0.048106, -0.001334, 0.048817, -0.000172,
//                                     0.001345, -0.000001, -0.001430, 0.000056, -0.000031, -0.000024,
//                                     0.000785, -0.000040, 0.000793, 0.000016, -0.001608, 0.000009,
//                                     -0.000004, -0.001925, 0.000002, -0.001920, 0.000002, -0.001960;
//         std::cout << "Decoupling matrix is set as: \n" << m_dDecouplingCoefficient << std::endl;
//         return true;
//     }

//     bool sendCommandAndGetResponse(const std::string& command, const std::string& successMsg) {
//         _tcp.Send(command);
//         std::string response = _tcp.read();
//         if (!response.empty()) {
//             std::cout << successMsg << response << std::endl;
//             return true;
//         } else {
//             std::cout << "Server not responding" << std::endl;
//             return false;
//         }
//     }

//     bool getAndPrintParameter(const std::string& command, Eigen::MatrixXd& parameter, const std::string& successMsg) {
//         _tcp.Send(command + "\r\n");
//         if (_tcp.GetChParameter(parameter)) {
//             std::cout << successMsg << parameter << std::endl;
//             return true;
//         } else {
//             std::cout << "Server not responding" << std::endl;
//             return false;
//         }
//     }

//     bool getAndPrintADCounts() {
//         _tcp.Send("AT+GOD\r\n");
//         if (_tcp.GetADCounts(m_nADCounts)) {
//             std::cout << "AD value: " << m_nADCounts << std::endl;
//             return true;
//         } else {
//             std::cout << "Server not responding" << std::endl;
//             return false;
//         }
//     }

//     void timer_callback() {
//         _tcp.readrecieveBuffer(m_nADCounts);
//         for (unsigned int i = 0; i < 6; ++i) {
//             m_dResultChValue(i) = 1000 * ((m_nADCounts(i) - m_dAmpZero(i)) / 65535.0 * 5.0) / m_dChnGain(i);
//         }
//         m_dDecouplingValue = m_dResultChValue * m_dDecouplingCoefficient.transpose();
//         std::cout << "Force is:\n" << m_dDecouplingValue << std::endl;

//         auto message = geometry_msgs::msg::Twist();
//         for (unsigned int i = 0; i < 6; ++i) {
//             message.linear.x = m_dDecouplingValue(0, i);
//         }
//         publisher_->publish(message);
//         ++count_;
//     }

//     Eigen::MatrixXd m_dResultChValue = Eigen::MatrixXd::Zero(1, 6);
//     Eigen::MatrixXd m_dDecouplingValue = Eigen::MatrixXd::Zero(1, 6);
//     Eigen::MatrixXd m_nADCounts = Eigen::MatrixXd::Zero(1, 6);
//     Eigen::MatrixXd m_dAmpZero = Eigen::MatrixXd::Zero(1, 6);
//     Eigen::MatrixXd m_dChnGain = Eigen::MatrixXd::Zero(1, 6);
//     Eigen::MatrixXd m_dDecouplingCoefficient = Eigen::MatrixXd::Zero(6, 6);
// };

// int main(int argc, char* argv[]) {
//     rclcpp::init(argc, argv);
//     rclcpp::spin(std::make_shared<ForceSensorPublisher>());
//     rclcpp::shutdown();
//     return 0;
// }

#include <signal.h>
#include "TCP_sock.hpp"
#include <Eigen/Dense>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace Eigen;
using namespace std;

TCPClient tcp;
#define M812X_CHN_NUMBER 6
MatrixXd m_dResultChValue = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_dDecouplingValue = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_nADCounts = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_dAmpZero = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_dChnGain = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_dChnEx = MatrixXd::Zero(1, M812X_CHN_NUMBER);
MatrixXd m_dDecouplingCoefficient(6, 6);

void sig_exit(int s)
{
    tcp.exit();
    exit(0);
}

bool ConfigSystem(void)
{
    // tcp.Send("AT+ADJZF=1;1;1;1;1;1\r\n");
    // sleep(3);
    //string rec = tcp.receive();
    // tcp.Send("AT+EGW=192.168.0.108\r\n");
    tcp.Send("AT+SGDM=(A01,A02,A03,A04,A05,A06);C;1;(WMA:1)\r\n");
    string rec = tcp.read();
    if (rec != "")
    {
        std::cout << "Server Response:" << rec << endl;
    }
    else
    {
        std::cout << "Server Not Response:" << endl;
    }

    tcp.Send("AT+SMPF=200\r\n");


    tcp.Send("AT+AMPZ=?\r\n");
    if (tcp.GetChParameter(m_dAmpZero))
    {
        std::cout << "AT+AMPZ=: " << m_dAmpZero << endl;
    }
    else
    {
        std::cout << "Server no Response:" << endl;
    }

    tcp.Send("AT+CHNAPG=?\r\n");
    if (tcp.GetChParameter(m_dChnGain))
    {
        std::cout << "AT+CHNAPG=: " << m_dChnGain << endl;
    }
    else
    {
        std::cout << "Server no Response:" << endl;
    }
    tcp.Send("AT+GOD\r\n");
    if (tcp.GetADCounts(m_nADCounts))
    {
        std::cout << "AD value:" << m_nADCounts << endl;
    }
    else
    {
        std::cout << "Server no Response:" << endl;
    }

    for (unsigned int i = 0; i < 6; ++i)
    {
        m_dResultChValue(i) = 1000 * ((m_nADCounts(i) - m_dAmpZero(i)) / (double)65535 * (double)5) / m_dChnGain(i);
        // m_dResultChValue(i) = 1000;
    }
    std::cout << "result value is : " << m_dResultChValue << std::endl;

    // m_dDecouplingCoefficient << 0.000130, 0.051905, 0.000135, -0.052493, 0.000118, 0.000096,
    //     0.000027, 0.030204, 0.000105, 0.030377, 0.000030, -0.060715,
    //     0.047253, -0.000245, 0.048106, -0.001334, 0.048817, -0.000172,
    //     0.001345, -0.000001, -0.001430, 0.000056, -0.000031, -0.000024,
    //     0.000785, -0.000040, 0.000793, 0.000016, -0.001608, 0.000009,
    //     -0.000004, -0.001925, 0.000002, -0.001920, 0.000002, -0.001960;

    // m_dDecouplingCoefficient << -0.001138, -0.000452, -0.000214, 0.0450414, -0.0014479, -0.044658,
    //                             0.0010779, -0.051190, 0.000550, 0.025747, 0.001326, 0.026049,
    //                             0.140930, 0.001818, 0.140952, 0.002624, 0.142324, -0.001066,
    //                             -0.000079, -0.000069, -0.001781, -0.000003, 0.001787, 0.000034,
    //                             0.002032, 0.000004, -0.001060, -0.000068, -0.0010921, 0.000049,
    //                             -0.000018, 0.000678, 0.000004, 0.000734, 0.000037, 0.000750;

    m_dDecouplingCoefficient << -1.13881, -0.45229, -0.21396, 45.04143, -1.44787, -44.65790,
                                1.07792, -51.18986, 0.55030, 25.74709, 1.32627, 26.04904,
                                140.93015, 1.81837, 140.95188, 2.62416, 142.32407, -1.06587,
                                -0.07948, -0.06875, -1.78083, -0.00327, 1.78707, 0.03365,
                                2.03181, 0.00437, -1.06020, -0.06827, -1.09210, 0.04894,
                                -0.01846, 0.67828, 0.00396, 0.73352, 0.03739, 0.75040;

    std::cout << "Decoupling matrix is set as: " << endl
                << m_dDecouplingCoefficient << std::endl;
    // m_dDecouplingValue = m_dResultChValue * m_dDecouplingCoefficient.transpose();
    // // m_dDecouplingValue = m_dResultChValue;
    // std::cout << "force is: " << endl
    //             << m_dDecouplingValue << std::endl;
    return true;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("talker");

    signal(SIGINT, sig_exit);
    if (tcp.setup("192.168.0.108", 4008) == true)
    {
        cout << "Force sensor has been connected!" << endl;
    }
    else
    {
        cout << "Force sensor connection failed!!!!!!!!!!!!!!!!!" << endl;
    }

    // Initialize the setting of the force sensor
    ConfigSystem();
    // Get real-time force sensor data
    tcp.Send("AT+GSD\r\n");

    auto chatter_pub = node->create_publisher<geometry_msgs::msg::Twist>("Force", 1000);
    auto force_msg = std::make_shared<geometry_msgs::msg::Twist>();

    rclcpp::Rate loop_rate(1000);

    int count = 0;
    while (rclcpp::ok())
    {
        // Read data from the force sensor
        tcp.readrecieveBuffer(m_nADCounts);
        for (unsigned int i = 0; i < 6; ++i)
        {
        m_dResultChValue(i) = 1000 * ((m_nADCounts(i) - m_dAmpZero(i)) / (double)65535 * (double)5) / m_dChnGain(i);
        }
        m_dDecouplingValue = m_dResultChValue * m_dDecouplingCoefficient.transpose();
        // m_dDecouplingValue = m_dResultChValue;
        std::cout << "force: " << endl
                << m_dDecouplingValue << std::endl;

        // Populate the ROS2 message
        force_msg->linear.x = m_dDecouplingValue(0, 0);
        force_msg->linear.y = m_dDecouplingValue(0, 1);
        force_msg->linear.z = m_dDecouplingValue(0, 2);
        force_msg->angular.x = m_dDecouplingValue(0, 3);
        force_msg->angular.y = m_dDecouplingValue(0, 4);
        force_msg->angular.z = m_dDecouplingValue(0, 5);

        // Publish the ROS2 message
        chatter_pub->publish(*force_msg);

        rclcpp::spin_some(node);
        loop_rate.sleep();
        ++count;
    }

    rclcpp::shutdown();
    return 0;
}