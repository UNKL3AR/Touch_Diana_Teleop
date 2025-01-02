#pragma once

#include "DianaAPIDef.h"

DIANA_API void initSrvNetInfo(srv_net_st *pinfo);

DIANA_API int initSrv(FNCERRORCALLBACK fnError, FNCSTATECALLBACK fnState, srv_net_st *pinfo);

DIANA_API int destroySrv(const char *strIpAddress = "");

DIANA_API int setPushPeriod(int intPeriod, /*IN*/ const char *strIpAddress = "");  //设置状态推送频率

DIANA_API int moveTCP(/*IN*/ tcp_direction_e d, /*IN*/ double v, /*IN*/ double a,
                      /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int rotationTCP(/*IN*/ tcp_direction_e d, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int moveJoint(/*IN*/ joint_direction_e d, /*IN*/ int i, /*IN*/ double v, /*IN*/ double a,
                        /*IN*/ const char *strIpAddress = "");

#define moveJ moveJToTarget

#define moveL moveLToPose

DIANA_API int speedJ(/*IN[7]*/ double *speed, /*IN*/ double a, /*option*/ double t,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int speedL(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t,
                     /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointPos(/*OUT[7]*/ double *joints, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointAngularVel(/*OUT[7]*/ double *vels, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointCurrent(/*OUT[7]*/ double *currents, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointTorque(/*OUT[7]*/ double *torques, /*IN*/ const char *strIpAddress = "");

DIANA_API int getTcpPos(/*OUT[6]*/ double *pose, /*IN*/ const char *strIpAddress = "");

DIANA_API double getTcpExternalForce(const char *strIpAddress = "");

DIANA_API int holdBrake(const char *strIpAddress = "");  // powerOff

DIANA_API int changeControlMode(
    mode_e m, /*IN*/ const char *strIpAddress = "");  // ChangeMode:Position, JointImpedance, CartImpedance

DIANA_API unsigned short getLibraryVersion();

DIANA_API const char *formatError(int e, /*IN*/ const char *strIpAddress = "");

DIANA_API int getLastError(const char *strIpAddress = "");

DIANA_API int setLastError(int e, /*IN*/ const char *strIpAddress = "");

DIANA_API int getLinkState(const char *strIpAddress = "");

DIANA_API int getTcpForce(/*OUT[6]*/ double *forces, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointForce(/*OUT[7]*/ double *forces, /*IN*/ const char *strIpAddress = "");

DIANA_API bool isCollision(const char *strIpAddress = "");

DIANA_API int initDHCali(/*IN[3*nrSets]*/ double *tcpMeas, /*IN[7*nrSets]*/ double *jntPosMeas,
                         /*[IN]*/ unsigned int nrSets, /*IN*/ const char *strIpAddress = "");

DIANA_API int getDHCaliResult(/*OUT[4*7]*/ double *rDH, /*OUT[6]*/ double *wRT,
                              /*OUT[3]*/ double *tRT,
                              /*OUT[2]*/ double *confid, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDH(/*IN[7]*/ double *a, /*IN[7]*/ double *alpha, /*IN[7]*/ double *d,
                    /*IN[7]*/ double *theta,
                    /*IN*/ const char *strIpAddress = "");

DIANA_API int setWrd2BasRT(/*IN[6]*/ double *RTw2b, /*IN*/ const char *strIpAddress = "");

DIANA_API int setFla2TcpRT(/*IN[3]*/ double *RTf2t, /*IN*/ const char *strIpAddress = "");

DIANA_API char getRobotState(const char *strIpAddress = "");

DIANA_API int resume(const char *strIpAddress = "");

DIANA_API int setJointCollision(/*IN[7]*/ double *collision, /*IN*/ const char *strIpAddress = "");

DIANA_API int setCartCollision(/*IN[6]*/ double *collision, /*IN*/ const char *strIpAddress = "");

DIANA_API int enterForceMode(/*[IN]*/ int intFrameType,
                             /*IN[16]*/ double *dblFrameMatrix,
                             /*IN[3]*/ double *dblForceDirection,
                             /*[IN]*/ double dblForceValue,
                             /*[IN]*/ double dblMaxApproachVelocity,
                             /*[IN]*/ double dblMaxAllowTcpOffset, /*IN*/ const char *strIpAddress = "");

DIANA_API int leaveForceMode(/*IN*/ int intExitMode, /*IN*/ const char *strIpAddress = "");

DIANA_API int setResultantCollision(/*IN*/ double force, /*IN*/ const char *strIpAddress = "");  //合力

#ifndef USE_JOINT_DAMP_RATIO
DIANA_API int setJointImpedance(/*IN[7]*/ double *arrStiff, /*IN[7]*/ double *arrDamp,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointImpedance(/*OUT[7]*/ double *arrStiff, /*OUT[7]*/ double *arrDamp,
                                /*IN*/ const char *strIpAddress = "");
#endif
#ifndef USE_CART_DAMP_RATIO
DIANA_API int setCartImpedance(/*IN[6]*/ double *arrStiff, /*IN[6]*/ double *arrDamp,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int getCartImpedance(/*OUT[6]*/ double *arrStiff, /*OUT[6]*/ double *arrDamp,
                               /*IN*/ const char *strIpAddress = "");
#endif

DIANA_API int zeroSpaceFreeDriving(/*IN*/ bool enable, /*IN*/ const char *strIpAddress = "");

DIANA_API int createPath(/*IN*/ int type, /*OUT*/ unsigned int &id_path,
                         /*IN*/ const char *strIpAddress = ""); /*1 for moveJ, 2 for moveL*/

DIANA_API int addMoveL(/*IN*/ unsigned int id_path, /*IN[7]*/ double *joints, /*IN*/ double vel,
                       /*IN*/ double acc,
                       /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJ(/*IN*/ unsigned int id_path, /*IN[7]*/ double *joints, /*IN*/ double vel_percent,
                       /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                       /*IN*/ const char *strIpAddress = "");

DIANA_API int runPath(/*IN*/ unsigned int id_path, /*IN*/ const char *strIpAddress = "");

DIANA_API int destroyPath(/*IN*/ unsigned int id_path, /*IN*/ const char *strIpAddress = "");

DIANA_API int rpy2Axis(/*IN[3]*/ double *arr);

DIANA_API int axis2RPY(/*IN[3]*/ double *arr);

DIANA_API int enableTorqueReceiver(/*bool*/ bool bEnable, /*IN*/ const char *strIpAddress = "");

#ifdef _API_SUPPORT_V2_
DIANA_API int sendTorque_rt(/*IN[7]*/ double *torque, /*IN*/ double t, /*IN*/ const char *strIpAddress = "");
#endif

DIANA_API int enableCollisionDetection(bool bEnable, /*IN*/ const char *strIpAddress = "");

DIANA_API int setActiveTcpPayload(/*IN[10]*/ double *payload, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoJ(/*IN[7]*/ double *joints, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int servoL(/*IN[6]*/ double *pose, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                     /*IN*/ double scale, /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoJ_ex(/*IN[7]*/ double *joints, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                        /*IN*/ bool realiable, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoL_ex(/*IN[6]*/ double *pose, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                        /*IN*/ double scale, /*IN*/ bool realiable, /*IN[6]*/ double *active_tcp = nullptr,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int speedJ_ex(/*IN[7]*/ double *speed, /*IN*/ double a, /*option*/ double t, /*IN*/ bool realiable,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int speedL_ex(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t, /*IN*/ bool realiable,
                        /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int dumpToUDisk(const char *strIpAddress = "");

DIANA_API int getJointLinkPos(/*OUT[7]*/ double *joints, /*IN*/ const char *strIpAddress = "");

DIANA_API int createComplexPath(/*IN*/ int complex_path_type, /*OUT*/ unsigned int &complex_path_id,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int runComplexPath(/*IN*/ unsigned int complex_path_id, /*IN*/ const char *strIpAddress = "");

DIANA_API int destroyComplexPath(/*IN*/ unsigned int complex_path_id, /*IN*/ const char *strIpAddress = "");

DIANA_API int saveEnvironment(const char *strIpAddress = "");

DIANA_API int dumpToUDiskEx(/*IN*/ double timeout_second, /*IN*/ const char *strIpAddress = "");

DIANA_API int enterForceMode_ex(/*IN[3]*/ double *dblForceDirection, /*[IN]*/ double dblForceValue,
                                /*[IN]*/ double dblMaxApproachVelocity, /*[IN]*/ double dblMaxAllowTcpOffset,
                                /*IN[6]*/ double *dblActiveTcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int readDI(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*OUT*/ int &value,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int readAI(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*OUT*/ int &mode, /*OUT*/ double &value,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int setAIMode(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int mode,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int writeDO(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int value,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int writeAO(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int mode, /*IN*/ double value,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int readBusCurrent(/*OUT*/ double &current, /*IN*/ const char *strIpAddress = "");

DIANA_API int readBusVoltage(/*OUT*/ double &voltage, /*IN*/ const char *strIpAddress = "");

DIANA_API int getDH(/*OUT[7]*/ double *aDH, /*OUT[7]*/ double *alphaDH, /*OUT[7]*/ double *dDH,
                    /*OUT[7]*/ double *thetaDH, /*IN*/ const char *strIpAddress = "");

DIANA_API int getOriginalJointTorque(/*OUT[7]*/ double *torques, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJacobiMatrix(/*OUT[7 * 6]*/ double *matrix_jacobi, /*IN*/ const char *strIpAddress = "");

DIANA_API int resetDH(const char *strIpAddress = "");

DIANA_API int runProgram(const char *programName, /*IN*/ const char *strIpAddress = "");

DIANA_API int stopProgram(const char *programName, /*IN*/ const char *strIpAddress = "");

DIANA_API int getVariableValue(const char *variableName, double &value, /*IN*/ const char *strIpAddress = "");

DIANA_API int setVariableValue(const char *variableName, const double &value, /*IN*/ const char *strIpAddress = "");

DIANA_API int isTaskRunning(const char *variableName, /*IN*/ const char *strIpAddress = "");

DIANA_API int pauseProgram(const char *strIpAddress = "");

DIANA_API int resumeProgram(const char *strIpAddress = "");

DIANA_API int stopAllProgram(const char *strIpAddress = "");

DIANA_API int isAnyTaskRunning(const char *strIpAddress = "");

DIANA_API int cleanErrorInfo(const char *strIpAddress = "");

DIANA_API int setCollisionLevel(int level, /*IN*/ const char *strIpAddress = "");

DIANA_API int mappingInt8Variant(const char *variantName, int index, /*IN*/ const char *strIpAddress = "");

DIANA_API int mappingDoubleVariant(const char *variantName, int index, /*IN*/ const char *strIpAddress = "");

DIANA_API int mappingInt8IO(const char *groupName, const char *name, int index, /*IN*/ const char *strIpAddress = "");

DIANA_API int mappingDoubleIO(const char *groupName, const char *name, int index, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMappingAddress(double *dblAddress, int doubleItemCount, int8_t *int8Address, int int8ItemCount,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int lockMappingAddress(const char *strIpAddress = "");

DIANA_API int unlockMappingAddress(const char *strIpAddress = "");

DIANA_API int getJointCount(const char *strIpAddress = "");

DIANA_API int getWayPoint(/*IN[64]*/ const char *waypointName, /*OUT[6]*/ double *dblTcppos,
                          /*OUT[7]*/ double *dblJoints, /*IN*/ const char *strIpAddress = "");

DIANA_API int setWayPoint(/*IN[64]*/ const char *waypointName, /*IN[6]*/ double *dblTcppos,
                          /*IN[7]*/ double *dblJoints, /*IN*/ const char *strIpAddress = "");

DIANA_API int addWayPoint(/*IN[64]*/ const char *waypointName, /*IN[6]*/ double *dblTcppos,
                          /*IN[7]*/ double *dblJoints, /*IN*/ const char *strIpAddress = "");

DIANA_API int deleteWayPoint(/*IN[64]*/ const char *waypointName, /*IN*/ const char *strIpAddress = "");

DIANA_API int setExternalAppendTorCutoffFreq(/*IN*/ double dblFreq, /*IN*/ const char *strIpAddress = "");

DIANA_API int zeroSpaceManualMove(/*IN*/ int direction, /*IN[7]*/ double *dblJointsVel,
                                  /*IN[7]*/ double *dblJointAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int setEndKeyEnableState(bool bEnable, const char *strIpAddress = "");

DIANA_API int updateForce(/*[IN]*/ double dblForceValue, /*IN*/ const char *strIpAddress = "");

DIANA_API int getSixAxiaForce(/*OUT[6]*/ double *dblForce, const char *strIpAddress = "");

DIANA_API int getInverseClosedResultSize(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");

DIANA_API int getInverseClosedJoints(/*IN*/ const int id, /*IN*/ const int index, /*OUT[7]*/ double *joints,
                                     /*IN*/ const char *strIpAddress = "");

DIANA_API int destoryInverseClosedItems(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");

#define nullSpaceFreeDriving zeroSpaceFreeDriving
#define nullSpaceManualMove zeroSpaceManualMove

DIANA_API int calculateJacobi(/*OUT[6*7]*/ double *dblJacobiMatrix, /*IN[7]*/ const double *dblJointPosition,
                              /*IN*/ int intJointCount, /*IN*/ const char *strIpAddress = "");

DIANA_API int calculateJacobiTF(/*OUT[6*7]*/ double *dblJacobiMatrix,
                                /*IN[7]*/ const double *dblJointPosition,
                                /*IN*/ int intJointCount, /*IN[6]*/ double *active_tcp = nullptr,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int getTcpForceInToolCoordinate(/*OUT[6]*/ double *forces, /*IN*/ const char *strIpAddress = "");

DIANA_API int speedLOnTcp(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int setControllerFeatureCode(/*IN*/ controller_feature intFeatureCode, /*IN*/ bool bEnable,
                                       /*IN*/ const char *strIpAddress = "");

DIANA_API int testControllerFeature(/*IN*/ controller_feature intFeatureCode, /*OUT*/ bool &bEnable,
                                    /*IN*/ const char *strIpAddress = "");

DIANA_API int getMechanicalJointsPositionRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                               /*IN*/ const char *strIpAddress = "");

DIANA_API int getMechanicalMaxJointsVel(/*OUT[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMechanicalMaxJointsAcc(/*OUT[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMechanicalMaxCartVelAcc(/*OUT*/ double &dblMaxCartTranslationVel,
                                         /*OUT*/ double &dblMaxCartRotationVel,
                                         /*OUT*/ double &dblMaxCartTranslationAcc,
                                         /*OUT*/ double &dblMaxCartRotationAcc,
                                         /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointsPositionRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                     /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxJointsVel(/*OUT[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxJointsAcc(/*OUT[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxCartTranslationVel(/*OUT*/ double &dblMaxCartTranslationVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxCartRotationVel(/*OUT*/ double &dblMaxCartRotationVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxCartTranslationAcc(/*OUT*/ double &dblMaxCartTranslationAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int getMaxCartRotationAcc(/*OUT*/ double &dblMaxCartRotationAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int setJointsPositionRange(/*IN[7]*/ double *dblMinPos, /*IN[7]*/ double *dblMaxPos,
                                     /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxJointsVel(/*IN[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxJointsAcc(/*IN[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxCartTranslationVel(/*IN*/ double dblMaxCartTranslationVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxCartRotationVel(/*IN*/ double dblMaxCartRotationVel, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxCartTranslationAcc(/*IN*/ double dblMaxCartTranslationAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int setMaxCartRotationAcc(/*OUT*/ double dblMaxCartRotationAcc, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointsSoftLimitRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                      /*IN*/ const char *strIpAddress = "");

DIANA_API int setJointsSoftLimitRange(/*IN[7]*/ double *dblMinPos, /*IN[7]*/ double *dblMaxPos,
                                      /*IN*/ const char *strIpAddress = "");

#ifdef USE_JOINT_DAMP_RATIO
DIANA_API int setJointImpeda(/*IN[7]*/ double *arrStiff, /*IN*/ double dblDampRatio,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointImpeda(/*OUT[7]*/ double *arrStiff, /*OUT*/ double *dblDampRatio,
                             /*IN*/ const char *strIpAddress = "");
#endif
#ifdef USE_CART_DAMP_RATIO
DIANA_API int setCartImpeda(/*IN[6]*/ double *arrStiff, /*IN*/ double dblDampRatio,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API int getCartImpeda(/*OUT[6]*/ double *arrStiff, /*OUT*/ double *dblDampRatio,
                            /*IN*/ const char *strIpAddress = "");
#endif

DIANA_API int getDefaultActiveTcp(/*OUT[16]*/ double *default_tcp, /*IN*/ const char *strIpAddress = "");

DIANA_API int getFunctionOptI4(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*OUT*/ int *intOptVal,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int setFunctionOptI4(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*IN*/ int intOptVal,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int getFunctionOptR8(/*IN*/ const int intFunctionIndex, /*IN*/ const int intOptName,
                               /*OUT*/ double *dblOptVal,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int setFunctionOptR8(/*IN*/ const int intFunctionIndex, /*IN*/ const int intOptName,
                               /*IN*/ const double dblOptVal,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int setThresholdTorque(/*IN[7]*/ double *threshold,
                                 /*IN*/ const char *strIpAddress = "");

DIANA_API int getThresholdTorque(/*OUT[7]*/ double *threshold,
                                 /*IN*/ const char *strIpAddress = "");

/*************************************** 以下是测试用函数 ***************************************/
#ifdef PRESS_TEST

DIANA_API void getTestData(int &fail, int &timeout, int &success, /*IN*/ const char *strIpAddress = "");
#endif
