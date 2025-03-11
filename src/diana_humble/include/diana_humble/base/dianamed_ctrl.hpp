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

    std::shared_ptr<KDL::ChainIkSolverPos_LMA> Piksolver;
    std::shared_ptr<KDL::ChainIkSolverVel_pinv_givens> PikVsolver;
    std::shared_ptr<KDL::ChainFkSolverPos_recursive> Pfksolver;
    std::shared_ptr<KDL::ChainJntToJacSolver> Pjacsolver;

    KDL::JntArray q_init;
    KDL::JntArray q_goal;
    KDL::Frame p_init;
    KDL::Frame p_goal;
    KDL::Frame pose_current_goal;//  change pose for camera control
    Eigen::Matrix<double,6,1> L;
    std::array<double,7> collision = {};

    DianaMedBase();
    ~DianaMedBase();
    //Diana initSrv function
    static void errorControl(int e);
    void DianaMedConnection();
    void Start();
    void Stop();
    void Switch_mode(_Mode Mode);
    void getTCPpose(double poses[6]);
    void test();
    void wait_move();
};

#endif 