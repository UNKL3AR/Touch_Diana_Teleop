#include "diana_humble/base/dianamed_ctrl.hpp"

int main(){
    DianaMedBase dianamed_ctrl;
    dianamed_ctrl.DianaMedConnection();
    dianamed_ctrl.Start();
    dianamed_ctrl.test();
    dianamed_ctrl.Stop();
    return 0;
}