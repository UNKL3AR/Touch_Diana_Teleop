﻿#pragma once

#include <string>

#define ETYPE_NO_ERROR 0
#define ETYPE_API_ERROR -1000
#define ETYPE_HARDWARE_ERROR -2000
#define ETYPE_COMMUNICATE_ERROR -2100
#define ETYPE_SYSTEM_ERROR -2200
#define ETYPE_ALGORITHM_ERROR -2300
#define ETYPE_OTHER_ERROR -3000

// warning
#define DECLARE_WARNING_SEGMENT(warning_segment, code) const int warning_segment = (-code);

#define DECLARE_WARNING_CODE(warning_name, warning_segment, code) \
    const int WARNING_CODE_##warning_name = (warning_segment - code);

// warning
#define WARNING_CODE_NO_WARNING 0
DECLARE_WARNING_SEGMENT(API_WARNING, 1000)
DECLARE_WARNING_CODE(RAID_PARTIAL_INVALID, API_WARNING, 1)
DECLARE_WARNING_CODE(JOINT_1_ENCODER_BATTERY_LOW, API_WARNING, 2)
DECLARE_WARNING_CODE(JOINT_2_ENCODER_BATTERY_LOW, API_WARNING, 3)
DECLARE_WARNING_CODE(JOINT_3_ENCODER_BATTERY_LOW, API_WARNING, 4)
DECLARE_WARNING_CODE(JOINT_4_ENCODER_BATTERY_LOW, API_WARNING, 5)
DECLARE_WARNING_CODE(JOINT_5_ENCODER_BATTERY_LOW, API_WARNING, 6)
DECLARE_WARNING_CODE(JOINT_6_ENCODER_BATTERY_LOW, API_WARNING, 7)
DECLARE_WARNING_CODE(JOINT_7_ENCODER_BATTERY_LOW, API_WARNING, 8)
DECLARE_WARNING_CODE(PREDICT_CONFLICTED_CALLING, API_WARNING, 9)
// error
#define NO_ERROR_CODE 0

#define USE_CART_DAMP_RATIO
#define USE_JOINT_DAMP_RATIO

#define DECLARE_ERROR_SEGMENT(error_segment, code) const int error_segment = (-code);

#define DECLARE_ERROR_CODE(error_name, error_segment, code) const int ERROR_CODE_##error_name = (error_segment - code);

// Api套接字错误
DECLARE_ERROR_SEGMENT(API_ERROR, 1000)
DECLARE_ERROR_CODE(WSASTART_FAIL, API_ERROR, 1)
DECLARE_ERROR_CODE(CREATE_SOCKET_FAIL, API_ERROR, 2)
DECLARE_ERROR_CODE(BIND_PORT_FAIL, API_ERROR, 3)
DECLARE_ERROR_CODE(SOCKET_READ_FAIL, API_ERROR, 4)
DECLARE_ERROR_CODE(SOCKET_TIMEOUT, API_ERROR, 5)
DECLARE_ERROR_CODE(RECVFROM_FAIL, API_ERROR, 6)
DECLARE_ERROR_CODE(SENDTO_FAIL, API_ERROR, 7)
DECLARE_ERROR_CODE(LOST_HEARTBEAT, API_ERROR, 8)
DECLARE_ERROR_CODE(LOST_ROBOTSTATE, API_ERROR, 9)
DECLARE_ERROR_CODE(GET_DH_FAILED, API_ERROR, 10)
DECLARE_ERROR_CODE(RELEASE_BRAKE_FAILED, API_ERROR, 11)
DECLARE_ERROR_CODE(HOLD_BRAKE_FAILED, API_ERROR, 12)
DECLARE_ERROR_CODE(IP_ADDRESS_NOT_REGISTER, API_ERROR, 13)
DECLARE_ERROR_CODE(ROBOTARM_OVERNUMBER, API_ERROR, 14)
DECLARE_ERROR_CODE(SOCKET_OTHER_ERROR, API_ERROR, 15)
DECLARE_ERROR_CODE(SOCKET_CONNECTED_ALREADY, API_ERROR, 16)
DECLARE_ERROR_CODE(UNKNOWN_ROBOTSTATE, API_ERROR, 17)
DECLARE_ERROR_CODE(RAID_INVALID, API_ERROR, 18)
DECLARE_ERROR_CODE(JOINT_ENCODER_BATTERY_LOW, API_ERROR, 19)

// 硬件错误
DECLARE_ERROR_SEGMENT(HARDWARE_ERROR, 2000)
DECLARE_ERROR_CODE(JOINT_REGIST_ERROR, HARDWARE_ERROR, 1)     //关节错误
DECLARE_ERROR_CODE(CURRENT_OFFSET_ERROR, HARDWARE_ERROR, 2)   // 0x00000001电流偏置错误
DECLARE_ERROR_CODE(EQEP_ENCODER, HARDWARE_ERROR, 3)           // 0x00000002高速侧编码器正交编码信号错误
DECLARE_ERROR_CODE(SPIENCODER, HARDWARE_ERROR, 4)             // 0x00000004与低速侧编码器通信断开
DECLARE_ERROR_CODE(HALL_SENSOR, HARDWARE_ERROR, 5)            // 0x00000008开关Hall相序错误
DECLARE_ERROR_CODE(CURRENT_BUS_OVERTIME, HARDWARE_ERROR, 6)   // 0x00000010母线电流长时间过载
DECLARE_ERROR_CODE(CURRENT_IQ_OVERTIME, HARDWARE_ERROR, 7)    // 0x00000020电机三相电流长时间过载
DECLARE_ERROR_CODE(POSITION_CMD_STEP, HARDWARE_ERROR, 8)      // 0x00000100位置指令阶跃错误
DECLARE_ERROR_CODE(TORQUE_SENSOR, HARDWARE_ERROR, 9)          // 0x00000200扭矩传感器信号故障1
DECLARE_ERROR_CODE(EEPROM_READ, HARDWARE_ERROR, 10)           // 0x00000400关节读EEPROM参数错误
DECLARE_ERROR_CODE(EEPROM_WRITE, HARDWARE_ERROR, 11)          // 0x00000800关节写EEPROM参数错误
DECLARE_ERROR_CODE(LS_ENCODER_OVERSPEED, HARDWARE_ERROR, 12)  // 0x00001000低速侧编码器反馈位置超速
DECLARE_ERROR_CODE(LS_ENCODER_FB_ERROR, HARDWARE_ERROR, 13)   // 0x00002000低速侧编码器反馈数据错误
DECLARE_ERROR_CODE(MS_SINGAL_Z_ERROR, HARDWARE_ERROR, 14)     // 0x00008000高速侧编码器Z信号异常
DECLARE_ERROR_CODE(THREE_PHASE_CURRENT, HARDWARE_ERROR, 15)   // 0x00010000电机三相电流瞬时过流
DECLARE_ERROR_CODE(TORQUE_SENSOR_READ_ERROR, HARDWARE_ERROR, 16)  // 0x80000000扭矩传感器读取故障

// 内部通讯错误
DECLARE_ERROR_SEGMENT(COMMUNICATION_ERROR, 2100)
DECLARE_ERROR_CODE(COMMUNICATE_ERROR, COMMUNICATION_ERROR, 1)
DECLARE_ERROR_CODE(LOST_HEART_WITH_DIANAROBOT_ERROR, COMMUNICATION_ERROR, 2)

// 系统错误
DECLARE_ERROR_SEGMENT(SYSTEM_ERROR, 2200)
DECLARE_ERROR_CODE(CALLING_CONFLICT_ERROR, SYSTEM_ERROR, 1)
DECLARE_ERROR_CODE(COLLISION_ERROR, SYSTEM_ERROR, 2)
DECLARE_ERROR_CODE(NOT_FOLLOW_POSITION_CMD, SYSTEM_ERROR, 3)
DECLARE_ERROR_CODE(NOT_FOLLOW_TCP_CMD, SYSTEM_ERROR, 4)
DECLARE_ERROR_CODE(NOT_ALL_AT_OP_STATE, SYSTEM_ERROR, 5)
DECLARE_ERROR_CODE(OUT_RANGE_FEEDBACK, SYSTEM_ERROR, 6)
DECLARE_ERROR_CODE(EMERGENCY_STOP, SYSTEM_ERROR, 7)
DECLARE_ERROR_CODE(NO_INIT_PARAMETER, SYSTEM_ERROR, 8)
DECLARE_ERROR_CODE(NOT_MATCH_LOAD, SYSTEM_ERROR, 9)
DECLARE_ERROR_CODE(CANNOT_MOVE_WHILE_FREE_DRIVING, SYSTEM_ERROR, 10)
DECLARE_ERROR_CODE(CANNOT_MOVE_WHILE_ZERO_SPACE_FREE_DRIVING, SYSTEM_ERROR, 11)
DECLARE_ERROR_CODE(PASSTHROUGH_FIFO_OVERFLOW_UP_ERROR, SYSTEM_ERROR, 12)
DECLARE_ERROR_CODE(PASSTHROUGH_FIFO_OVERFLOW_DOWN_ERROR, SYSTEM_ERROR, 13)
DECLARE_ERROR_CODE(ROBOT_IN_VIRTUAL_WALL, SYSTEM_ERROR, 14)
DECLARE_ERROR_CODE(CONFLICT_TASK_RUNNING, SYSTEM_ERROR, 15)
DECLARE_ERROR_CODE(OUT_OF_PHYSICAL_RANGE_FEEDBACK, SYSTEM_ERROR, 16)
DECLARE_ERROR_CODE(PARAMETER_POINTER_EQUALS_NULLPTR, SYSTEM_ERROR, 17)      // 输入参数不能为空
DECLARE_ERROR_CODE(PARAMETER_EQUALS_NAN_OR_INF, SYSTEM_ERROR, 18)           // 输入参数存在nan或者inf
DECLARE_ERROR_CODE(UNKNOWN_FIRMWARE_VERSION, SYSTEM_ERROR, 19)              // 未知的固件版本
DECLARE_ERROR_CODE(INPUT_OUT_OF_EXTREME_POSITION_RANGE, SYSTEM_ERROR, 20)   // 输入超出关节极限位置
DECLARE_ERROR_CODE(INPUT_OUT_OF_PHYSICAL_POSITION_RANGE, SYSTEM_ERROR, 21)  // 输入超出物理限位
DECLARE_ERROR_CODE(NOT_IN_SAFETY_HANDLE_MODE, SYSTEM_ERROR, 22)             // 未处在安全处理模式
DECLARE_ERROR_CODE(INCOMPATIBLE_FIRMWARE_VERSION, SYSTEM_ERROR, 23)  // 电流环自由驱动不兼容的固件版本
DECLARE_ERROR_CODE(JOINT_IMPEDANCE_DECLINED_IN_SAFETY_HANDLE, SYSTEM_ERROR, 24)  // 安全处理模式下禁止切换到关节阻抗模式
DECLARE_ERROR_CODE(CART_IMPEDANCE_DECLINED_IN_SAFETY_HANDLE, SYSTEM_ERROR, 25)  // 安全处理模式下禁止切换到笛卡尔阻抗
DECLARE_ERROR_CODE(CART_IMPEDANCE_PARAMETER_OUT_OF_RANGE, SYSTEM_ERROR, 26)   // 笛卡尔阻抗参数超限
DECLARE_ERROR_CODE(JOINT_IMPEDANCE_PARAMETER_OUT_OF_RANGE, SYSTEM_ERROR, 27)  // 关节阻抗参数超限
DECLARE_ERROR_CODE(UNABLE_TO_GET_JOINTS_POSITION, SYSTEM_ERROR, 28)           // 无法获取关节极限位置
DECLARE_ERROR_CODE(PAYLOAD_MASS_OUT_OF_RANGE, SYSTEM_ERROR, 29)               // 负载质量超限
DECLARE_ERROR_CODE(LOCK_JOINT_INVERSE_FAILED, SYSTEM_ERROR, 30)               // 锁轴逆解失败
DECLARE_ERROR_CODE(TCP_POSE_VECTOR_PARAMETER_OUT_OF_RANGE, SYSTEM_ERROR, 31)  // 位姿向量超限
DECLARE_ERROR_CODE(VEL_OR_ACC_PARAMETER_OUT_OF_RANGE, SYSTEM_ERROR, 32)       // 速度或加速度超限
DECLARE_ERROR_CODE(POINTS_CANT_FORM_PLANE, SYSTEM_ERROR, 33)       // 三点无法构成有效平面
DECLARE_ERROR_CODE(POINTS_TOO_CLOSE, SYSTEM_ERROR, 34)       // 三点距离过近
DECLARE_ERROR_CODE(NOT_IN_IMPEDANCE_CONTROL_RULE, SYSTEM_ERROR, 35)  // 不在阻抗控制规则下

// 算法错误
DECLARE_ERROR_SEGMENT(ALGORITHM_ERROR, 2300)
DECLARE_ERROR_CODE(PLAN_ERROR, ALGORITHM_ERROR, 1)
DECLARE_ERROR_CODE(INTERPOLATE_POSITION_ERROR, ALGORITHM_ERROR, 2)
DECLARE_ERROR_CODE(INTERPOLATE_TORQUE_ERROR, ALGORITHM_ERROR, 3)
DECLARE_ERROR_CODE(SINGULAR_VALUE_ERROR, ALGORITHM_ERROR, 4)
DECLARE_ERROR_CODE(PLANNER_ERROR, ALGORITHM_ERROR, 5)
DECLARE_ERROR_CODE(HOME_POSITION_ERROR, ALGORITHM_ERROR, 6)
DECLARE_ERROR_CODE(FATAL, ALGORITHM_ERROR, 7)                       // 严重错误(关节位置超出物理极限)
DECLARE_ERROR_CODE(POS_LIMIT, ALGORITHM_ERROR, 8)                   // 位置超出限制
DECLARE_ERROR_CODE(FORCE_LIMIT, ALGORITHM_ERROR, 9)                 // 关节力矩超出限制
DECLARE_ERROR_CODE(SPEED_LIMIT, ALGORITHM_ERROR, 10)                // 速度超出限制
DECLARE_ERROR_CODE(ACC_LIMIT, ALGORITHM_ERROR, 11)                  // 加速度超出限制
DECLARE_ERROR_CODE(JERK_LIMIT, ALGORITHM_ERROR, 12)                 // 加加速度超出限制
DECLARE_ERROR_CODE(MOTION_LIMIT, ALGORITHM_ERROR, 13)               // 位置超出限制
DECLARE_ERROR_CODE(IK_TRACK, ALGORITHM_ERROR, 14)                   // 轨迹跟踪过程逆解求解失败
DECLARE_ERROR_CODE(IK_GENERAL, ALGORITHM_ERROR, 15)                 // 通用位置逆解求解失败
DECLARE_ERROR_CODE(PLAN_INPUT, ALGORITHM_ERROR, 16)                 // 轨迹规划输入错误
DECLARE_ERROR_CODE(PLAN_MOVJ, ALGORITHM_ERROR, 17)                  // 关节空间轨迹规划失败
DECLARE_ERROR_CODE(PLAN_MOVL, ALGORITHM_ERROR, 18)                  // 直线轨迹规划失败
DECLARE_ERROR_CODE(PLAN_MOVC, ALGORITHM_ERROR, 19)                  // 圆弧轨迹规划失败
DECLARE_ERROR_CODE(PLAN_BLEND, ALGORITHM_ERROR, 20)                 // 过渡轨迹规划失败
DECLARE_ERROR_CODE(PLAN_SPDJ, ALGORITHM_ERROR, 21)                  // SpeedJ轨迹规划失败
DECLARE_ERROR_CODE(PLAN_SPDL, ALGORITHM_ERROR, 22)                  // SpeedL轨迹规划失败
DECLARE_ERROR_CODE(PLAN_SRVJ, ALGORITHM_ERROR, 23)                  // ServoJ轨迹规划失败
DECLARE_ERROR_CODE(PLAN_SRVL, ALGORITHM_ERROR, 24)                  // ServoL轨迹规划失败
DECLARE_ERROR_CODE(MOVE_UNKNOWN, ALGORITHM_ERROR, 25)               // 未知运动类型或运动类型不匹配
DECLARE_ERROR_CODE(MOVE_UNPLAN, ALGORITHM_ERROR, 26)                // 轨迹未规划
DECLARE_ERROR_CODE(MOVE_INPUT, ALGORITHM_ERROR, 27)                 // 轨迹插补输入错误
DECLARE_ERROR_CODE(MOVE_INTERP, ALGORITHM_ERROR, 28)                // 轨迹插补失败
DECLARE_ERROR_CODE(PLAN_TRANSLATION, ALGORITHM_ERROR, 29)           // 移动规划失败
DECLARE_ERROR_CODE(PLAN_ROTATION, ALGORITHM_ERROR, 30)              // 旋转规划失败
DECLARE_ERROR_CODE(PLAN_JOINTS, ALGORITHM_ERROR, 31)                // 关节规划失败
DECLARE_ERROR_CODE(UNMATCHED_JOINTS_NUMBER, ALGORITHM_ERROR, 32)    // 零空间自由驱动关节数不匹配
DECLARE_ERROR_CODE(TCPCALI_FUTILE_WPS, ALGORITHM_ERROR, 33)         // 示教点不合理
DECLARE_ERROR_CODE(TCPCALI_FIT_FAIL, ALGORITHM_ERROR, 34)           // 拟合TCP失败
DECLARE_ERROR_CODE(DHCALI_FIT_WF_FAIL, ALGORITHM_ERROR, 35)         // DH参数初始化世界坐标系失败
DECLARE_ERROR_CODE(DHCALI_FIT_TF_FAIL, ALGORITHM_ERROR, 36)         // DH参数初始化工具坐标系失败
DECLARE_ERROR_CODE(DHCALI_FIT_DH_FAIL, ALGORITHM_ERROR, 37)         // // DH参数拟合失败
DECLARE_ERROR_CODE(DHCALI_INIT_FAIL, ALGORITHM_ERROR, 38)           // DH参数初始化失败
DECLARE_ERROR_CODE(SLFMOV_SINGULAR, ALGORITHM_ERROR, 39)            // 零空间运动至奇异位置
DECLARE_ERROR_CODE(SLFMOV_FUTILE, ALGORITHM_ERROR, 40)              // 零空间运动在笛卡尔空间内无效
DECLARE_ERROR_CODE(SLFMOV_JNTLIM, ALGORITHM_ERROR, 41)              // 零空间运动至关节限位
DECLARE_ERROR_CODE(SLFMOV_SPDLIM, ALGORITHM_ERROR, 42)              // 零空间运动至关节限位
DECLARE_ERROR_CODE(SLFMOV_FAIL, ALGORITHM_ERROR, 43)                // 零空间运动插补失败
DECLARE_ERROR_CODE(SLFMOV_FFC_FAIL, ALGORITHM_ERROR, 44)            // 零空间运动前馈补偿错误
DECLARE_ERROR_CODE(LOADIDENT_INIT_FAIL, ALGORITHM_ERROR, 45)        // 负载辨识初始化失败
DECLARE_ERROR_CODE(LOADIDENT_UFB_FAIL, ALGORITHM_ERROR, 46)         // 负载辨识更新反馈数据错误
DECLARE_ERROR_CODE(LOADIDENT_FIT_FAIL, ALGORITHM_ERROR, 47)         // 负载辨识失败
DECLARE_ERROR_CODE(LOADIDENT_NONLOADED, ALGORITHM_ERROR, 48)        // 未检测到有效负载
DECLARE_ERROR_CODE(INTERPOLATE_CURRENT_ERROR, ALGORITHM_ERROR, 49)  // 插补电流失败

// 其它错误
DECLARE_ERROR_SEGMENT(OTHER_ERROR, 3000)
DECLARE_ERROR_CODE(RESOURCE_UNAVAILABLE, OTHER_ERROR, 1)
DECLARE_ERROR_CODE(DUMP_LOG_TIMEOUT, OTHER_ERROR, 2)
DECLARE_ERROR_CODE(DUMP_LOG_FAILED, OTHER_ERROR, 3)
DECLARE_ERROR_CODE(RESET_DH_FAILED, OTHER_ERROR, 4)
DECLARE_ERROR_CODE(SIX_AXIS_DEVICE_OFFLINE, OTHER_ERROR, 5)      // 六维力离线
DECLARE_ERROR_CODE(ILLEGAL_PARAMETER, OTHER_ERROR, 6)            // API接口函数传入非法参数
DECLARE_ERROR_CODE(PREDICT_MODE_CONFLICT, OTHER_ERROR, 7)        // 运动预测模式下冲突调用
DECLARE_ERROR_CODE(ROBOT_TCP_OVER_SPEED, OTHER_ERROR, 8)         // 机器人tcp超速
DECLARE_ERROR_CODE(ROBOT_JOINTS_OVER_SPEED, OTHER_ERROR, 9)      // 机器人关节超速
DECLARE_ERROR_CODE(ROBOT_TCP_OUT_OF_CART_ZONE, OTHER_ERROR, 10)  // 机器人TCP超过笛卡尔限制空间

//#define TEACH_PENDANT_SERVER_IP      "192.168.3.87"//"127.0.0.1"//
#define TEACH_PENDANT_SERVER_IP "192.168.10.75"  //"127.0.0.1"//
#define LOCAL_IP "127.0.0.1"                     //"192.168.3.87"//

#define TEACH_PENDANT_SERVER_PORT 8888
#define TEACH_PENDANT_SERVER_TIMEOUT 3000  // 1s
#define LOCAL_PORT 0                       // 9999

#define HEARTBEAT_SERVER_PORT 4444
#define HEARTBEAT_SLEEP_TIME 100  // 100ms
#define HEARTBEAT_TIMEOUT 100     // 100ms
#define LOCAL_HEARTBEAT_PORT 0    // 5555

#define ROBOT_STATE_SERVER_PORT 6666
#define ROBOT_STATE_SLEEP_TIME 10  // 10ms
#define ROBOT_STATE_TIMEOUT 100    // 1s
#define LOCAL_ROBOT_STATE_PORT 0   // 7777

#define REALTIME_CONTROL_PORT 3333
#define LOCAL_REALTIME_PORT 0

#define MAX_HEARTBEAT_TOLERANT_LOST_TIMES 15
#define MAX_ROBOTSTATE_RECV_LOST_TIMES (15)

#ifndef MAX_JOINT_COUNT
#define MAX_JOINT_COUNT 7
#endif

#ifndef DIANA_JOINT_COUNT
#define DIANA_JOINT_COUNT 7
#endif

#ifndef THOR_JOINT_COUNT
#define THOR_JOINT_COUNT 6
#endif

#ifndef TCP_POSE_SIZE
#define TCP_POSE_SIZE 6
#endif

#define ERROR_MESSAGE_LEN 64

#define MAX_JACOBI_MATRIX_SIZE TCP_POSE_SIZE* MAX_JOINT_COUNT
