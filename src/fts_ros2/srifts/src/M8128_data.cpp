#include "M8128_data.hpp"

TurnOnSensor::TurnOnSensor(): Node("SRI_node"),Sampling_Time(0){
    memset(&Receive_Data,0,sizeof(Receive_Data));
    this->declare_parameter("usart_port_name", "/dev/ttyUSB0");
    this->declare_parameter("serial_baud_rate", 115200);
    usart_port_name = this->get_parameter("usart_port_name").as_string();
    serial_baud_rate = this->get_parameter("serial_baud_rate").as_int();
    M8128_data_publisher = this->create_publisher<sri_interface::msg::SixAxisFTS>("/M3733C_Force_Sensor", 10);
    RCLCPP_INFO(this->get_logger(), "Data ready");

    try{
        M8128_Serial.setPort(usart_port_name);
        M8128_Serial.setBaudrate(serial_baud_rate);
        serial::Timeout _time = serial::Timeout::simpleTimeout(2000);
        M8128_Serial.setTimeout(_time);
        M8128_Serial.open();
    }
    catch(serial::IOException& e){
        RCLCPP_ERROR(this->get_logger(),"Force sensor cannot open serial port. Please check the serial port cable!");
    }
    if(M8128_Serial.isOpen()){
        RCLCPP_INFO(this->get_logger(), "Force sensor serial port opened");
        // M8128_Serial.write(zero);
        // sleep(3);
        // RCLCPP_INFO(this->get_logger(), "zero");
        M8128_Serial.write(sample_freq);
        RCLCPP_INFO(this->get_logger(), "Force sensor start");
        M8128_Serial.write(start_cmd);
    }

    timer_ = this->create_wall_timer(std::chrono::milliseconds(10), std::bind(&TurnOnSensor::sensor_run, this));
}

TurnOnSensor::~TurnOnSensor(){
    M8128_Serial.write(end_cmd);
    RCLCPP_INFO(this->get_logger(), "TurnOnSensor deconstruction fun!");
}

void TurnOnSensor::M8128_data_publisher_fun(){
    sri_interface::msg::SixAxisFTS sensor_msgs;
    sensor_msgs.x_force = M8128_data.X_force;
    sensor_msgs.y_force = M8128_data.Y_force;
    sensor_msgs.z_force = M8128_data.Z_force;
    sensor_msgs.x_torque = M8128_data.X_torque;
    sensor_msgs.y_torque = M8128_data.Y_torque;
    sensor_msgs.z_torque = M8128_data.Z_torque;
    sensor_msgs.sampling_time = Sampling_Time;
    sensor_msgs.frame_number = M8128_data.frame_number;

    M8128_data_publisher->publish(sensor_msgs);
}

unsigned char TurnOnSensor::Check_Sum(){
    unsigned char check_sum = 0, k;
    unsigned char Count_Number = 24;
    for(k = 0; k < Count_Number; k++){
        check_sum = check_sum + Receive_Data.rx[k + 5];
    }
    RCLCPP_INFO(this->get_logger(), "check_sum = %d", check_sum);
    return check_sum;
}

bool TurnOnSensor::Get_Sensor_Data(){
    short j = 0, Header_Pos = 0, Tail_Pos = 0; 
    uint8_t Receive_Data_Pr[RECEIVE_DATA_SIZE] = {0};
    unsigned char byte[4] = {0};
    M8128_Serial.read(Receive_Data_Pr, sizeof(Receive_Data_Pr));
    for(j=0;j<31;j++){
        if(Receive_Data_Pr[j]==FRAME_HEADER)
            Header_Pos=j;
        else if(Receive_Data_Pr[j]==FRAME_TAIL)
            Tail_Pos=j;    
    }
    if(Tail_Pos==(Header_Pos+30)){
        memcpy(Receive_Data.rx, Receive_Data_Pr, sizeof(Receive_Data_Pr));
    }
    else if(Header_Pos==(1+Tail_Pos)){
        for(j=0;j<31;j++)
          Receive_Data.rx[j]=Receive_Data_Pr[(j+Header_Pos)%31];
    }
    else {
        return false;
    }    
    Receive_Data.Frame_Header = Receive_Data.rx[0];
    Receive_Data.Frame_Tail = Receive_Data.rx[30];  

    if (Receive_Data.Frame_Header == FRAME_HEADER ){
        if (Receive_Data.Frame_Tail == FRAME_TAIL) {
            if (Receive_Data.rx[29] == Check_Sum()){
                M8128_data.frame_number =  Receive_Data.rx[3]*256 + Receive_Data.rx[4]; 

                byte[0] = Receive_Data.rx[5];
                byte[1] = Receive_Data.rx[6];
                byte[2] = Receive_Data.rx[7];
                byte[3] = Receive_Data.rx[8];
                Byte_to_Float(&(M8128_data.X_force), byte);

                byte[0] = Receive_Data.rx[9];
                byte[1] = Receive_Data.rx[10];
                byte[2] = Receive_Data.rx[11];
                byte[3] = Receive_Data.rx[12];
                Byte_to_Float(&(M8128_data.Y_force), byte);

                byte[0] = Receive_Data.rx[13];
                byte[1] = Receive_Data.rx[14];
                byte[2] = Receive_Data.rx[15];
                byte[3] = Receive_Data.rx[16];
                Byte_to_Float(&(M8128_data.Z_force), byte);

                byte[0] = Receive_Data.rx[17];
                byte[1] = Receive_Data.rx[18];
                byte[2] = Receive_Data.rx[19];
                byte[3] = Receive_Data.rx[20];
                Byte_to_Float(&(M8128_data.X_torque), byte);

                byte[0] = Receive_Data.rx[21];
                byte[1] = Receive_Data.rx[22];
                byte[2] = Receive_Data.rx[23];
                byte[3] = Receive_Data.rx[24];
                Byte_to_Float(&(M8128_data.Y_torque), byte);

                byte[0] = Receive_Data.rx[25];
                byte[1] = Receive_Data.rx[26];
                byte[2] = Receive_Data.rx[27];
                byte[3] = Receive_Data.rx[28];
                Byte_to_Float(&(M8128_data.Z_torque), byte);
                
                return true;
            }
        }
    } 
    return false;
}

void TurnOnSensor::sensor_run(){
    last_time = this->get_clock()->now();
    while(rclcpp::ok()){
        now_ = this->get_clock()->now();
        if(true==Get_Sensor_Data()){
            Sampling_Time = (now_-last_time).seconds();
            M8128_data_publisher_fun();
            last_time = now_;
        }
    }
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "SRI Six Axis Force Torque Sensor Data");
    auto node = std::make_shared<TurnOnSensor>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}