#include "diana_humble/base/dianamed_ctrl.hpp"
#include "diana_humble/kdl/diana_kdl_model.hpp"

DianaMedBase::DianaMedBase(){
    DianaMedConnection();
    q_joints_states = std::make_shared<std::vector<double>>(7,0.0);  //std::vector<double>{}
    joint_data_ = std::make_unique<double[]>(7);                     // {0.0} *7
    
    chain = KDL::Diana();                                            //init robot_tree
    //step of numeracal iksolver LMA
    L << 1 ,1 ,1 ,0.01 ,0.01 ,0.01;

    Piksolver = std::make_shared<KDL::ChainIkSolverPos_LMA>(chain,L);
    Pfksolver = std::make_shared<KDL::ChainFkSolverPos_recursive>(chain);
    Pjacsolver = std::make_shared<KDL::ChainJntToJacSolver>(chain);
    PikVsolver = std::make_shared<KDL::ChainIkSolverVel_pinv_givens>(chain);

    NbOfJoints = chain.getNrOfJoints();
    q_init.resize(NbOfJoints);                                     //input joints for iksolver
    q_goal.resize(NbOfJoints);                                     //output joints for iksolver
    
    p_goal.p = KDL::Vector::Zero();
    p_goal.M = KDL::Rotation::Identity();
    p_init.p = KDL::Vector::Zero();
    p_init.M = KDL::Rotation::Identity();
}

DianaMedBase::~DianaMedBase(){
    delete pInfo;
    pInfo = nullptr;
}

void DianaMedBase::DianaMedConnection(){
    DianaMedIpAddress = "192.168.0.110";  //Robot IP address
    pInfo = new srv_net_st();
    memset(pInfo->SrvIp,0x00,sizeof(pInfo->SrvIp));
    memcpy(pInfo->SrvIp,DianaMedIpAddress,strlen(DianaMedIpAddress));
    pInfo->LocHeartbeatPort = 0;
    pInfo->LocRobotStatePort = 0;
    pInfo->LocSrvPort = 0;
    initSrv(nullptr,nullptr,pInfo);
    collision.fill(100.0);
    setJointCollision(collision.data(), DianaMedIpAddress);
}

void DianaMedBase::errorControl(int e){
    const char * strError = formatError(e); 
    printf("error code (%d):%s\n", e, strError);
}


//release brake
void DianaMedBase::Start(){
    int ret;
    ret = releaseBrake (DianaMedIpAddress);   //release brake   
    if (ret == 0){
        std::cout << "Diana Release Brake  ! " << std::endl;
    }                                   
}

void DianaMedBase::Stop(){
    holdBrake (DianaMedIpAddress);                                       
    destroySrv (DianaMedIpAddress);
    std::cout << "Stop moving control ! " << std::endl;
}

void DianaMedBase::getTCPpose(double poses[6]){ 
    getTcpPos(poses, DianaMedIpAddress); 
}


void DianaMedBase::Switch_mode(_Mode Mode){
    int ret = changeControlMode(Mode, DianaMedIpAddress); 
    std::cout<<"Dianamed control mode switches to"<< Mode << "control"<<std::endl;
}


void DianaMedBase::wait_move(){
    usleep(20000);
    while (true){
        const char state = getRobotState(DianaMedIpAddress);
        if (state != 0){
            break;
        }else{
            usleep(1000);
        }
    }
    stop(DianaMedIpAddress);
}

// void DianaMedBase::test(){
//     Switch_mode(T_MODE_CART_IMPEDANCE);
//     for(int i = 0;i<100000;i++){
//         std::cout << i <<std::endl;
//     }   
// }
