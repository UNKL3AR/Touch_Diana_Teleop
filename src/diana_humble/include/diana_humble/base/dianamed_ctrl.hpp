#ifndef DIANAMED_CTRL_HPP
#define DIANAMED_CTRL_HPP
//CPP_std_header
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstring>
#include <chrono>
//for shared_ptr
#include <memory>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Eigen>
#include <Eigen/Geometry>

//DianaMed_API
#include "diana_humble/dianamedApi/DianaAPI.h"
#include "diana_humble/dianamedApi/DianaAPIDef.h"
#include "diana_humble/dianamedApi/DianaApiCommon.h"
#include "diana_humble/dianamedApi/DianaApiSpecial.h"
#include "diana_humble/dianamedApi/FunctionOptDef.h"
#include "diana_humble/dianamedApi/Environment.h"

#include <kdl/chain.hpp>
#include <kdl/utilities/utility.h>
#include <kdl/frames_io.hpp>
#include <kdl/chainiksolvervel_pinv_givens.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/chainiksolverpos_lma.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>


#include <kdl/trajectory.hpp>
#include <kdl/trajectory_segment.hpp>
#include <kdl/trajectory_composite.hpp>
#include <kdl/velocityprofile_trap.hpp>
#include <kdl/path_roundedcomposite.hpp>
#include <kdl/path_line.hpp>
#include <kdl/rotational_interpolation_sa.hpp>
#include <kdl/utilities/error.h>


class DianaMedBase
{
public:
    const char* DianaMedIpAddress;
    srv_net_st* pInfo;
    KDL::Chain chain;
    unsigned int NbOfJoints;

    double initJoints[7];
    double targetJoints[7];
    double joints[7];
    std::shared_ptr<std::vector<double>> q_joints_states;
    std::unique_ptr<double[]> joint_data_; 

    // for KDL interface 
    KDL::ChainIkSolverPos_LMA *Piksolver;
    KDL::ChainIkSolverVel_pinv_givens *PikVsolver; // cartesian space v to joint space v
    KDL::ChainFkSolverPos_recursive *Pfksolver;
    KDL::ChainJntToJacSolver *Pjacsolver;
    KDL::JntArray q_init;
    KDL::JntArray q_goal;
    KDL::Frame p_init;
    KDL::Frame p_goal;
    KDL::Frame pose_current_goal;//  change pose for camera control
    Eigen::Matrix<double,6,1> L;

    DianaMedBase();
    ~DianaMedBase();

    //Diana initSrv function
    // static void logRobotState(StrRobotStateInfo *pinfo);
    static void errorControl(int e);
    void DianaMedConnection();
    void Start();
    void Stop();
    void Switch_mode(_Mode Mode);
    void getTCPpose(double poses[6]);
    void test(); //this function is for testing
    void wait_move();
};

#endif 