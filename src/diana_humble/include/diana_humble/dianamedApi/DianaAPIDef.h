/**
 * 此文件是为API接口数据结构定义的头文件
 */
#pragma once

#pragma pack(1)

#ifdef _WIN32
#include <stdint.h>
#else
#include <sys/types.h>
#endif
#include "Environment.h"

// 下列 ifdef 块是创建使从 DLL 导出更简单的宏的标准方法。
// 此 DLL 中的所有文件都是用命令行上定义的 DIANA_API_EXPORTS 符号编译的。
// 在使用此 DLL 的任何其他项目上不应定义此符号。
// 这样，源文件中包含此文件的任何其他项目都会将 DIANA_API_EXPORTS 函数视为是从 DLL 导入的，
// 而此 DLL 则将用此宏定义的符号视为是被导出的。

#if defined _WIN32
#ifdef DIANA_API_EXPORTS
#define DIANA_API extern "C" __declspec(dllexport)
#else
#define DIANA_API extern "C" __declspec(dllimport)
#endif
#else
#if __GNUC__ >= 4
#define DIANA_API extern "C" __attribute__((visibility("default")))
#else
#define DIANA_API extern "C"
#endif
#endif

//这里是工业和医疗共有数据结构
#define _API_SUPPORT_V2_

#define MAX_SUPPORT_ROBOTARM_NUM 3

extern "C" typedef void (*FNCERRORCALLBACK)(int e, const char *strIpAddress);

extern "C" typedef struct _SrvNetSt {
    char SrvIp[32];
    unsigned short LocHeartbeatPort;
    unsigned short LocRobotStatePort;
    unsigned short LocSrvPort;
    unsigned short LocRealtimeSrvPort;
} srv_net_st;

extern "C" typedef enum _MoveTCPDirection {
    T_MOVE_X_UP,
    T_MOVE_X_DOWN,
    T_MOVE_Y_UP,
    T_MOVE_Y_DOWN,
    T_MOVE_Z_UP,
    T_MOVE_Z_DOWN
} tcp_direction_e;

extern "C" typedef enum _MoveJointDirection {
    T_MOVE_UP = 0,
    T_MOVE_DOWN,
} joint_direction_e;

typedef enum _Mode {
    T_MODE_INVALID = -1,
    T_MODE_POSITION = 0,
    T_MODE_JOINT_IMPEDANCE,
    T_MODE_CART_IMPEDANCE,
} mode_e;

enum COMPLEX_PATH_TYPE {
    NORMAL_JOINT_PATH = 0,
    MOVEP_JOINT_PATH = 1,
    NORMAL_POSE_PATH = 2,
    MOVEP_POSE_PATH = 3,
};

extern "C" typedef enum _CONTROLLER_FEATURE_CODE {
    NONE_FEATURE = 0,
    AUTO_SWITCH_TO_IMPEDANCE_MODE_WHEN_COLLISION_DETECTED = 1,
} controller_feature;

extern "C" typedef struct _ErrorInfo {
    int errorId;
    int errorType;
    int errorCode;
    char errorMsg[64];
} StrErrorInfo;

#define USER_MAXIMUM_DOUBLE_SIZE 40
#define USER_MAXIMUM_INT8_SIZE 160

extern "C" typedef struct _CustomStateInfo {
    double dblField[USER_MAXIMUM_DOUBLE_SIZE];
    int8_t int8Field[USER_MAXIMUM_INT8_SIZE];
} StrCustomStateInfo;

//这里是医疗API特有的数据结构
// TrajectoryState
extern "C" typedef struct _TrajectoryState {
    int taskId;
    int segCount;
    int segIndex;
    int errorCode;
    int isPaused;
    int isSafetyDriving;
    int isFreeDriving;
    int isZeroSpaceFreeDriving;
    int isHoldBrake;
    int isProgramRunningOrPause;
    int isTeachPendantPaused;
    int isControllerTerminated;
    int isTorqueReceiverEnable;
} StrTrajectoryState;

//用户层机械臂反馈状态结构体
extern "C" typedef struct _RobotStateInfo {
    double jointPos[7];
    double jointAngularVel[7];
    double jointCurrent[7];
    double jointTorque[7];
    double tcpPos[6];
    double tcpExternalForce;
    bool bCollision;
    bool bTcpForceValid;
    double tcpForce[6];
    double jointForce[7];
    StrTrajectoryState trajState;
    StrErrorInfo errorInfo;
    double sixAxisForce[6];
    bool bSixAxisForceValid;
} StrRobotStateInfo;

extern "C" typedef void (*FNCSTATECALLBACK)(StrRobotStateInfo *pinfo, const char *strIpAddress);

extern "C" typedef enum _ConstrainType {
    E_CONSTRAIN_TYPE_NONE = 0,
    E_CONSTRAIN_LOCKED_J3 = 3,
    E_CONSTRAIN_LOCKED_J7 = 7,
} constrain_type_e;

extern "C" typedef enum _SIX_AXIS_TYPE {
    SIX_AXIS_IN_FREE_DRIVING = 0,
    SIX_AXIS_IN_FORCE_MODE,
    SIX_AXIS_IN_JOINT_IMPEDANCE,
    SIX_AXIS_IN_CART_IMPEDANCE,
} six_axis_type_e;

struct LoadIdentificationWaypoint {
    double joints[MAX_JOINT_COUNT];
    double vel;
};

struct LoadIdentificationParam {
    LoadIdentificationParam(bool valid = false, double mass = 0.0, LoadIdentificationWaypoint *arr = nullptr,
                            int len = 0)
        : bIsMassValid(valid), dblMass(mass), arrWaypoints(arr), arrWaypointsSize(len) {}
    bool bIsMassValid;                         // default:false
    double dblMass;                            // default:0.0,
    LoadIdentificationWaypoint *arrWaypoints;  // default:nullptr,
    int arrWaypointsSize;                      // default:0
};
extern "C" typedef bool (*FNCSTOP)(const char *strIpAddress);

typedef struct color_rgb {
public:
    color_rgb(uint8_t r = 255, uint8_t g = 255, uint8_t b = 255) : red(r), green(g), blue(b) {}

public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} led_color;

#pragma pack()
