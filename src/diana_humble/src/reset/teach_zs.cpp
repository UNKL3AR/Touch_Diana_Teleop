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

int main()
{
    const char* strIpAddress = "192.168.0.110";
    srv_net_st* pinfo = new srv_net_st();
    strcpy(pinfo->SrvIp,"192.168.0.110");
    initSrv(nullptr,nullptr, pinfo);
    releaseBrake (strIpAddress);
    joint_direction_e dtype =T_MOVE_UP; 
    int index = 1; 
    double vel = 0.8; 
    double acc = 0.8; 
    int ret = moveJoint(dtype, index, vel, acc, strIpAddress); 
    if(ret < 0) 
    { 
        printf( "moveJoint failed! Return value = %d\n ", ret); 
    } 
    usleep(3000); 
    stop(strIpAddress); 
    holdBrake (strIpAddress);
    destroySrv(strIpAddress);
    return 0;

}