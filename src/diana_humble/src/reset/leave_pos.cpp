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
    double joint[7] = {-0.00780791, 0.521499, 0.00485942, 1.68705, -0.0240645, -0.0546483 ,1.57988 };
    double vel = 0.3;
    double acc = 0.3;
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