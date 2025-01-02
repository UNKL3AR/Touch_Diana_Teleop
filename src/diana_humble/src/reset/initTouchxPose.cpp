#include <memory.h>
#include <ctime>
#include <unistd.h>
#include <math.h>
#include <iostream>

#include "diana_humble/dianamedApi/DianaAPI.h"
#include "diana_humble/dianamedApi/DianaAPIDef.h"

void logRobotState(StrRobotStateInfo *pinfo){}
void errorControl(int e){
    const char * strError = formatError(e); 
    printf("error code (%d):%s\n", e, strError);
}

void wait_move(const char* strIpAddress){
    usleep(20000);
    while (true){
        const char state = getRobotState(strIpAddress);
        if (state != 0){
            break;
        }
        else{
            usleep(1000);
        }
    }
    stop(strIpAddress);
}

int main(){
    const char* strIpAddress = "192.168.0.110";
    srv_net_st* pinfo = new srv_net_st();
    strcpy(pinfo->SrvIp,"192.168.0.110");
    initSrv(nullptr,nullptr, pinfo);
    releaseBrake (strIpAddress);
    // double joint[7] = {-1.52967 ,0.35674, -0.0283069,2.17795 ,0.0336156 ,-0.60977 ,-0.00971939  };
    double joint[7] = {-0.01383, 0.532705, 0.010528, 2.09436, -0.0228301, -0.490275, 1.57379 };
    double vel = 0.5;
    double acc = 0.5;
    moveJ(joint, vel, acc, strIpAddress);
    wait_move(strIpAddress);

    double joints[7] = {0.0};
    getJointPos(joints,strIpAddress);
    for (int i = 0;i<7;i++){
        std::cout << joints[i] <<" ";
    }
    std::cout<<std::endl;
    holdBrake (strIpAddress);
    destroySrv(strIpAddress);
    return 0;
}