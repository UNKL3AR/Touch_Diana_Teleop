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
    double joints[7] = {0.0};
    getJointPos(joints,strIpAddress);
    std::cout <<"joint"<<std::endl;
    for (int i = 0;i<7;i++){
        std::cout << joints[i] <<" ";
    }
    std::cout<<std::endl;

    double poses[6] = {0.0};
    int ret = getTcpPos(poses, strIpAddress);
    if(ret < 0){
        printf( "getTcpPos failed! Return value = %d\n ", ret);
    }
    std::cout <<"TCP"<<std::endl;
    for(int i = 0;i < 6;i++){
        std::cout << poses[i] << " ";
    }
    std::cout << std::endl;

    double dblForce[6] = {0};
    getSixAxiaForce (dblForce,strIpAddress);

    std::cout <<"force"<<std::endl;
    for(int i = 0;i < 6;i++){
        std::cout << dblForce[i] << " ";
    }
    std::cout << std::endl;

    holdBrake (strIpAddress);
    destroySrv(strIpAddress);
    return 0;
}