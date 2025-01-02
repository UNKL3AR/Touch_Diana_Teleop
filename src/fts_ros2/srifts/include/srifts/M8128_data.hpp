#ifndef _M8128_DATA_AC_
#define _M8128_DATA_AC_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/u_int16.hpp>
#include "serial/serial.h"
#include "sri_interface/msg/six_axis_fts.hpp"

#define FRAME_HEADER      0X55
#define FRAME_TAIL        0XAA
#define RECEIVE_DATA_SIZE 31

typedef union
{
    float fdata;
    uint32_t ldata;
} FloatLongType;

void Float_to_Byte(float f, uint8_t byte[]){
	FloatLongType fl;
	fl.fdata=f;
	byte[0]=(unsigned char)fl.ldata;
	byte[1]=(unsigned char)(fl.ldata>>8);
	byte[2]=(unsigned char)(fl.ldata>>16);
	byte[3]=(unsigned char)(fl.ldata>>24);
}

void Byte_to_Float(float *f, uint8_t byte[]){
	FloatLongType fl;
	fl.ldata=0;
	fl.ldata=byte[3];
	fl.ldata=(fl.ldata<<8)|byte[2];
	fl.ldata=(fl.ldata<<8)|byte[1];
	fl.ldata=(fl.ldata<<8)|byte[0];
	*f=fl.fdata;
}

typedef struct _Force_Data_{
    unsigned int frame_number;
    float X_force;
    float Y_force;
    float Z_force;
    float X_torque;
    float Y_torque;
    float Z_torque;
}Force_Data;

typedef struct _M8128_Receive_Data_{
    uint8_t rx[RECEIVE_DATA_SIZE];
    // uint8_t Flag_Stop;
    unsigned char Frame_Header; //1个字节 帧头
    uint16_t frame_number;
    float X_force;
    float Y_force;
    float Z_force;
    float X_torque;
    float Y_torque;
    float Z_torque;
    unsigned char Frame_Tail; //1个字节  帧尾 校验位
}M8128_Receive_Data;

class TurnOnSensor : public rclcpp::Node
{
public:
    TurnOnSensor();
    ~TurnOnSensor();
    void sensor_run();
    serial::Serial M8128_Serial;

private:
    std::string start_cmd = "AT+GSD\r\n";
    std::string sample_freq = "AT+SMPF=100\r\n";
    std::string end_cmd = "AT+GOD\r\n";
    // std::string zero = "AT+ADJZF=1;1;1;1;1;1\r\n";
    bool Get_Sensor_Data();
    unsigned char Check_Sum();
    Force_Data M8128_data;
    void M8128_data_publisher_fun();
    int serial_baud_rate;
    std::string usart_port_name, robot_frame_id, smoother_cmd_vel;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sri_interface::msg::SixAxisFTS>::SharedPtr M8128_data_publisher;
    M8128_Receive_Data Receive_Data;
    rclcpp::Time now_, last_time;
    float Sampling_Time;
};

#endif
