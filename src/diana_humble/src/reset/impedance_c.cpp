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
    // // double joint[7] = {-1.52967 ,0.35674, -0.0283069,2.17795 ,0.0336156 ,-0.60977 ,-0.00971939  };
    // double joint[7] = {-0.01383, 0.532705, 0.010528, 2.09436, -0.0228301, -0.490275, 1.57379 };
    // double vel = 0.5;
    // double acc = 0.5;
    // moveJ(joint, vel, acc, strIpAddress);
    // wait_move(strIpAddress);
    int ret = changeControlMode(T_MODE_POSITION, strIpAddress);
    if(ret < 0)
    {
    printf( "changeControlMode failed! Return value = %d\n ", ret);
    }

    double dblFirstMoveLPosition [7] = {0.19306, 0.605455, -0.0287923 ,2.06183 ,0.0308948 ,-0.472227 ,1.70715};
    double dblSecondMoveLPosition [7] = {0.188506, 0.699639, -0.0231597 ,2.04561 ,0.0338788, -0.394329 ,1.7048};
    double dblThirdMoveLPosition [7] = {-0.162836, 0.699345, 0.01658, 2.04635, -0.0330287, -0.393718 ,1.44553};
    double dblForthMoveLPosition [7] = {-0.165496, 0.604946, 0.0202232 ,2.06257 ,-0.0306678 ,-0.471999 ,1.44351};
    unsigned int path_id = 0;
    printf("start test moveL path.\n");
    // const char* strIpAddress = "192.168.10.75";
    createPath(2, path_id,strIpAddress);
    addMoveL(path_id, dblFirstMoveLPosition, 0.1, 0.2, 0,strIpAddress);
    addMoveL(path_id, dblSecondMoveLPosition, 0.1, 0.2, 0,strIpAddress);
    addMoveL(path_id, dblThirdMoveLPosition, 0.1, 0.2, 0,strIpAddress);
    addMoveL(path_id, dblForthMoveLPosition, 0.1, 0.2, 0,strIpAddress);
    runPath(path_id,strIpAddress);
    destroyPath(path_id,strIpAddress);
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
