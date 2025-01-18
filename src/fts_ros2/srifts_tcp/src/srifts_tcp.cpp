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