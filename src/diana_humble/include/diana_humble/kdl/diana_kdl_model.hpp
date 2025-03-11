#ifndef DIANA_MODEL_HPP
#define DIANA_MODEL_HPP

#include <kdl/chain.hpp>
#include <kdl/utilities/utility.h>
#include <Eigen/Dense>
#include <cmath>

#include <vector>
#include <kdl/chain.hpp>
#include <kdl/frames.hpp>
#include <kdl/joint.hpp>
#include <kdl/segment.hpp>

namespace KDL {

Chain Diana() {
    Chain diana;

    // DH 参数 (单位：米 & 弧度)
    std::vector<double> a     = {0.0, 0.0, 0.0, 0.065, -0.0528, 0.0, 0.077};
    std::vector<double> d     = {-0.2985, 0.0, -0.4591, 0.0, -0.4574, -0.0050, -0.1059};
    std::vector<double> alpha = {M_PI, M_PI_2, -M_PI_2, M_PI_2, -M_PI_2, -M_PI_2, -M_PI_2};
    std::vector<double> theta = {0.0, 0.0, 0.0, 0.0, 0.0, M_PI, 0.0};

    // 基座部分
    diana.addSegment(Segment("base_link", Joint(Joint::None), 
                             Frame::DH(0, alpha[0], d[0], 0)));
    
    // 迭代添加关节和连杆
    for (size_t i = 1; i < a.size(); i++) {
        diana.addSegment(Segment("joint" + std::to_string(i), Joint(Joint::RotZ)));
        diana.addSegment(Segment("link" + std::to_string(i), Joint(Joint::None), 
                                 Frame::DH(a[i], alpha[i], d[i], theta[i])));
    }

    return diana;
}

} // namespace KDL
#endif //DIANA_MODEL_HPP