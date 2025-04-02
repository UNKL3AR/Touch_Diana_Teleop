#include "diana_humble/base/dianamed_ctrl.hpp"
#include "diana_humble/kdl/diana_kdl_model.hpp"

using namespace KDL;

//Constructor
DianaMedBase::DianaMedBase(){
    DianaMedConnection();
    q_joints_states = std::make_shared<std::vector<double>>(7,0.0); //std::vector<double>{}
    joint_data_ = std::make_unique<double[]>(7);// {0.0} *7
    
    chain = KDL::Diana();                                          //init robot_tree
    L(0)=1;L(1)=1;L(2)=1;L(3)=0.01;L(4)=0.01;L(5)=0.01;            //step of numeracal iksolver LMA
    Piksolver = new KDL::ChainIkSolverPos_LMA(chain,L);
    Pfksolver = new KDL::ChainFkSolverPos_recursive(chain);
    Pjacsolver = new KDL::ChainJntToJacSolver(chain);
    PikVsolver = new KDL::ChainIkSolverVel_pinv_givens(chain);

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
    double collision[7] = {100, 100, 100, 100, 100, 100, 100};
    setJointCollision(collision, DianaMedIpAddress);
}


// void DianaMedBase::logRobotState(StrRobotStateInfo *pInfo){}

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


//hold brake and destroy real robot 1KHZ control service
void DianaMedBase::Stop(){
    holdBrake (DianaMedIpAddress);                                       
    destroySrv (DianaMedIpAddress);
    std::cout << "Stop moving control ! " << std::endl;
}

// void DianaMedBase::MotorPosControl(){
//     if((joint_data_)[0] == NULL){
//         auto q = std::make_unique<double[]>(7);
//         getJointPos(q.get(),DianaMedIpAddress);
//         sendPassThroughJoints_rt(q.get(), DianaMedIpAddress);
//     }else{
//         sendPassThroughJoints_rt(joint_data_.get(), DianaMedIpAddress);
//     }
// }


// void DianaMedBase::MotorTorqControl(){
//     //still be compeleted !
// }

// void DianaMedBase::getJointStates(){
//     double q[NbOfJoints] = {0.0};
//     getJointPos(q,DianaMedIpAddress);
//     for (int i = 0; i < 7; i++){
//         q_joints_states->push_back(q[i]);
//     }
// }

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


// void DianaMedBase::MoveJ(double joints[7],double vel,double acc){

//     int ret;
//     ret = moveJToTarget(joints, vel, acc, DianaMedIpAddress);
//     if(ret < 0)
//     {
//         printf("MoveJ failed!\n");
//     }
//     wait_move();
// }

// void DianaMedBase::printJointStates(){
//     std::cout << "Current joint states is :";
//     for (const auto& val : *q_joints_states){
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
// }

void DianaMedBase::test(){
    Switch_mode(T_MODE_CART_IMPEDANCE);
    for(int i = 0;i<100000;i++){
        std::cout << i <<std::endl;
    }   
}


// int main()
// {
//     auto base = std::make_shared<DianaMedBase>();
//     base->Start();
//     base->test();
//     base->Stop();
//     return 0;
// }