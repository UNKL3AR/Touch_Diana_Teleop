#include <memory.h>
#include <ctime>
#include <unistd.h>
#include <math.h>
#include <iostream>
#include "diana_humble/dianamedApi/DianaAPI.h"
#include "diana_humble/dianamedApi/DianaAPIDef.h"

int main(){
    const char* strIpAddress = "192.168.10.75";
    srv_net_st* pinfo = new srv_net_st();
    strcpy(pinfo->SrvIp,"192.168.10.75");
    initSrv(nullptr,nullptr, pinfo);

    const char* strCurrentNetworkInfo = "192.168.10.75";
    const char* strTargetNetworkInfo = "192.168.0.110";

    if (setRobotNetworkInfo (strCurrentNetworkInfo,strTargetNetworkInfo, strIpAddress) < 0)
    {
        printf("Diana API setRobotNetworkInfo failed!\n");
    }

    destroySrv(strIpAddress);
    return 0;
}