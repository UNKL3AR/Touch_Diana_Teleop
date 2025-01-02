#pragma once

#include "DianaAPIDef.h"

DIANA_API int moveJToTarget(/*IN[7]*/ double *joints, /*IN*/ double v, /*IN*/ double a,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API int moveJToPose(/*IN[6]*/ double *pose, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "",
                          /*IN*/ const constrain_type_e eConstrainType = E_CONSTRAIN_TYPE_NONE,
                          /*IN*/ double dblConstrainValue = 0.0);

DIANA_API int moveLToTarget(/*IN[7]*/ double *joints, /*IN*/ double v, /*IN*/ double a,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API int moveLToPose(/*IN[6]*/ double *pose, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "",
                          /*IN*/ const constrain_type_e eConstrainType = E_CONSTRAIN_TYPE_NONE,
                          /*IN*/ const double dblConstrainValue = 0.0);

DIANA_API int freeDriving(bool enable, /*IN*/ const char *strIpAddress = "");

DIANA_API int stop(const char *strIpAddress = "");

DIANA_API int forward(/*IN[7]*/ double *joints, /*OUT[6]*/ double *pose, /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int inverse(/*IN[6]*/ double *pose, /*OUT[7]*/ double *joints, /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int releaseBrake(const char *strIpAddress = "");  // powerOn

// setDefaultActiveTcp:该函数将会改变moveTCP，rotationTCP，moveJToPose，moveLToPose，speedJ，speedL，forward，inverse，getTcpPos，getTcpExternalForce的默认行为。
DIANA_API int setDefaultActiveTcp(/*IN[16]*/ double *default_tcp, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDefaultActiveTcpPose(/*IN[6]*/ double *arrPose, /*IN*/ const char *strIpAddress = "");

DIANA_API int homogeneous2Pose(/*IN[16]*/ double *matrix, /*OUT[6]*/ double *pose);

DIANA_API int pose2Homogeneous(/*IN[6]*/ double *pose, /*OUT[16]*/ double *matrix);

DIANA_API int inverse_ext(/*IN[7]*/ double *ref_joints, /*IN[6]*/ double *pose,
                          /*OUT[7]*/ double *joints,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveLByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *target_joints, /*IN*/ double vel,
                               /*IN*/ double acc, /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveLByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *target_pose, /*IN*/ double vel,
                             /*IN*/ double acc, /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *target_joints,
                               /*IN*/ double vel_percent, /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *target_pose,
                             /*IN*/ double vel_percent, /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveCByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *pass_joints,
                               /*IN[7]*/ double *target_joints, /*IN*/ double vel, /*IN*/ double acc,
                               /*IN*/ double blendradius, /*IN*/ bool ignore_rotation,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveCByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *pass_pose,
                             /*IN[6]*/ double *target_pose, /*IN*/ double vel, /*IN*/ double acc,
                             /*IN*/ double blendradius, /*IN*/ bool ignore_rotation,
                             /*IN*/ const char *strIpAddress = "");

/*****************************************
 * function name: getHomingState
 * -1: get state failed
 *  0: home position
 *  1: running
 *  2: homing stop with error
 *  3: not at home position = need homing
 * **************************************/
DIANA_API int getHomingState(const char *strIpAddress = "");

DIANA_API int startHoming(const char *strIpAddress = "");

DIANA_API int getCartImpedanceCoordinateType(const char *strIpAddress = "");

DIANA_API int setCartImpedanceCoordinateType(const int intCoordinateType, const char *strIpAddress = "");

DIANA_API int getInertiaMatrix(/*IN[7]*/ double *dblMotorPosition, /*OUT[7*7]*/ double *dblInerMatrix,
                               const char *strIpAddress = "");

DIANA_API int inverseClosedFull(/*IN[6]*/ const double *pose, /*IN*/ const int lock_joint_index,
                                /*IN*/ const double lock_joint_position, /*IN[7]*/ double *ref_joints,
                                /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int inverseClosedIdeal(/*IN[6]*/ const double *pose, /*IN*/ const double lock_robot_arm_angle,
                                 /*IN[7]*/ double *ref_joints,
                                 /*IN[6]*/ double *active_tcp = nullptr,
                                 /*IN*/ const char *strIpAddress = "");

DIANA_API int getInverseClosedIdealResultSize(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");

DIANA_API int getInverseClosedIdealJoints(/*IN*/ const int id, /*IN*/ const int index, /*OUT*/ double *joints,
                                          /*IN*/ const char *strIpAddress = "");

DIANA_API int destoryInverseClosedIdealItems(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");

DIANA_API int getSixAxisZeroOffset(/*OUT[10]*/ double *dblZeroOffset, /*IN*/ const char *strIpAddress = "");

DIANA_API int setSixAxisZeroOffset(/*IN[10]*/ double *dblZeroOffset, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDefaultActiveWorkpiece(/*IN[16]*/ double *dblWop, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDefaultActiveWorkpiecePose(/*IN[6]*/ double *dblWopPose,
                                            /*IN*/ const char *strIpAddress = "");

DIANA_API int getDefaultActiveWorkpiece(/*OUT[16]*/ double *dblWop, /*IN*/ const char *strIpAddress = "");

DIANA_API int getDefaultActiveWorkpiecePose(/*OUT[6]*/ double *dblWopPose,
                                            /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDriving_ex(/*IN*/ bool enable, /*[IN]*/ int intFrameType,
                             /*IN[6]*/ double *dblForceDirection,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API int enableSixAxis(/*IN*/ six_axis_type_e type, /*IN & OUT*/ bool &bEnable,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API bool isSixAxisEnabled(/*IN*/ six_axis_type_e type, /*IN*/ const char *strIpAddress = "");

DIANA_API int calcRobotArmAngle(/*IN[7]*/ double *dblJoints, /*OUT*/ double &dblAngle,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDrivingWithLockedJoint(bool enable, /*IN*/ int intLockedJntIndex = -1,
                                         /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDrivingWithLockedJoint_ex(/*IN*/ bool enable, /*[IN]*/ int intFrameType,
                                            /*IN[6]*/ double *dblForceDirection,
                                            /*IN*/ int intLockedJntIndex = -1, /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDrivingForCurrentLoop(bool enable, /*IN*/ const char *strIpAddress = "");

DIANA_API int getCurrentLoopFreeDrivingState(/*IN*/ const char *strIpAddress = "");

DIANA_API int setJointLockedInCartImpedanceMode(/*IN*/ const bool bLock, /*IN*/ const int intLockedJointIndex = 2,
                                                /*IN*/ const char *strIpAddress = "");
DIANA_API int getJointLockedInCartImpedanceMode(/*OUT*/ bool &isLocked, /*IN*/ const char *strIpAddress = "");

DIANA_API int enterSafetyIdle(/*IN*/ const char *strIpAddress = "");

DIANA_API int leaveSafetyIdle(/*IN*/ const char *strIpAddress = "");

/***********************************
 *  identifyTcpPayload 函数返回值含义
 *  0：成功
 * -1：其他错误
 * -2：无法读取关节扭矩
 * -3：初始化失败
 * -4：采样失败
 * -5：传送辨识数据失败
 * -6：结果不可信
 * -7：负载辨识失败
 * -8：回调函数中断负载辨识
 * -9:robot正在执行负载辨识任务
 * -10:开启辨识失败
 * -11:结束负载辨识失败
 * -12:robot正在执行示教程序
 * -14:in forceMode
 * *********************************/
DIANA_API int identifyTcpPayload(/*OUT[10]*/ double *dblResult, /*IN*/ FNCSTOP fnNeedStop = nullptr,
                                 /*IN*/ LoadIdentificationParam *ptrParam = nullptr,
                                 /*IN*/ const char *strIpAddress = "");

DIANA_API int getRgbLedState(/*OUT[7]*/ led_color *rgbLedColor, /*IN*/ const char *strIpAddress = "");

DIANA_API int setRgbLedState(/*IN[7]*/ led_color *rgbLedColor, /*IN*/ const char *strIpAddress = "");

DIANA_API int getRobotNetworkInfo(char *strNetworkInfo, /*option*/ const char *strIpAddress = "");

DIANA_API int setRobotNetworkInfo(const char *strCurrentNetworkInfo, const char *strTargetNetworkInfo,
                                  /*option*/ const char *strIpAddress = "");

DIANA_API int setGravInfo(/*IN[3]*/ double *dblGravityAccInBase, /*IN*/ const char *strIpAddress = "");

DIANA_API int getGravInfo(/*OUT[3]*/ double *dblGravityAccInBase, /*IN*/ const char *strIpAddress = "");

DIANA_API int getSixAxisInstallation(/*OUT*/ double *dblMass, /*OUT[3]*/ double *dblCenterOfMass,
                                     /*OUT[16]*/ double *dblPoseOfSixAxisInFalan,
                                     /*OUT[3]*/ double *dblGravityAccInBase,
                                     /*IN*/ const char *strIpAddress = "");

DIANA_API int initSixAxisInstallation(/*IN*/ double dblMass, /*IN[3]*/ double *dblCenterOfMass,
                                      /*IN[16]*/ double *dblPoseOfSixAxisInFalan,
                                      /*IN[3]*/ double *dblGravityAccInBase,
                                      /*IN*/ const char *strIpAddress = "");

DIANA_API int getCalcSixAxisWaypoints(/*OUT[7]*/ double *dblHomePoint, /*OUT*/ double &dblHomeVel,
                                      /*OUT*/ double &dblHomeAcc,
                                      /*OUT[36]*/ double *dblWaypoints, /*OUT[6]*/ double *dblWPVels,
                                      /*OUT[6]*/ double *dblWPAccs,
                                      /*IN*/ const char *strIpAddress = "");

DIANA_API int identifyTcpPayloadWithSixAxis(/*OUT[10]*/ double *dblPayload, /*IN[7]*/ double *dblHomePoint,
                                            /*IN*/ double dblHomeVel, /*IN*/ double dblHomeAcc,
                                            /*IN[36]*/ double *dblWaypoints, /*IN[6]*/ double *dblWPVels,
                                            /*IN[6]*/ double *dblWPAccs, /*IN*/ int size,
                                            /*IN*/ FNCSTOP fnNeedStop = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int getFixedSixAxisForce(/*OUT[6]*/ double *dblFixedForce, /*IN*/ const char *strIpAddress = "");

DIANA_API int setSixAxisSensorAbsAccuracy(/*IN[6]*/ double *dblAccuracy,
                                          /*IN*/ const char *strIpAddress = "");

DIANA_API int getSixAxisSensorAbsAccuracy(/*OUT[6]*/ double *dblAccuracy,
                                          /*IN*/ const char *strIpAddress = "");

DIANA_API int updateResistForce(/*IN[3]*/ double *force_direction, /*IN*/ const double &distance,
                                const char *strIpAddress = "");

DIANA_API int setTcpPayloadWithSixAxis(/*IN*/ const double dblMass, /*IN[3]*/ double *dblMassCenter,
                                       /*IN*/ const char *strIpAddress = "");

DIANA_API int getTcpPayloadWithSixAxis(/*OUT*/ double &dblMass, /*OUT[3]*/ double *dblMassCenter,
                                       /*IN*/ const char *strIpAddress = "");

DIANA_API int getStaticFriction(bool &bEnable, /*OUT*/ double &dblVelocity, /*OUT*/ double &dblForce,
                                /*OUT*/ double &dblTorque, const char *strIpAddress = "");

DIANA_API int setStaticFriction(bool bEnable, /*IN*/ double dblVelocity, /*IN*/ double dblForce,
                                /*IN*/ double dblTorque, const char *strIpAddress = "");

DIANA_API int setPredictMoveMode(const bool bEnable, const int intSamples = 1000, const char *strIpAddress = "");

DIANA_API bool getPredictMoveMode(const char *strIpAddress = "");

DIANA_API int getSafetySpeedLimit(/*OUT[6]*/ double *dblTcpSpeedLimit,
                                  /*OUT[7]*/ double *dblJointsSpeedLimit,
                                  /*IN*/ const char *strIpAddress = "");

DIANA_API int setSafetySpeedLimit(/*IN[6]*/ double *dblTcpSpeedLimit, /*IN[7]*/ double *dblJointsSpeedLimit,
                                  /*IN*/ const char *strIpAddress = "");

DIANA_API int getEncoderBatteryLevel(/*OUT[7]*/ int *arrBatteryLevels, /*IN*/ const char *strIpAddress = "");

DIANA_API int getWarningList(/*OUT[MAX_WARNING_NUM]*/ int *arrWarningCodes, /*IN*/ const int len,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API const char *formatWarning(/*IN*/ int w, /*IN*/ const char *strIpAddress = "");

DIANA_API int cleanWarning(/*IN*/ const char *strIpAddress = "");

DIANA_API int setSafetyCartZone(/*IN[3]*/ const double *dblTcpPos, /*IN[3]*/ const double *dblCartFreeZone,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int getSafetyCartZone(/*OUT[3]*/ double *dblTcpPos, /*OUT[3]*/ double *dblCartFreeZone,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int calibrateSixAxisSensor(/*IN*/ const char *strIpAddress = "");

DIANA_API int calcInstallAngle(/*IN[TCP_POSE_SIZE]*/ const double *dblPose1, /*IN[TCP_POSE_SIZE]*/ const double *dblPose2, 
            /*IN[TCP_POSE_SIZE]*/ const double *dblPose3, /*OUT*/ double *angle, /*IN*/ const char *strIpAddress = " ");

DIANA_API int updateRealtimeVirtualWall(bool enteredDecelerationBoundary, double distance2HazardousBoundary,
                                        double *safetyDirection, const char *strIpAddress = "");