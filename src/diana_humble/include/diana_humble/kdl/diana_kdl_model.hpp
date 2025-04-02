// #ifndef DIANA_MODEL_HPP
// #define DIANA_MODEL_HPP

// #include <kdl/chain.hpp>
// #include <kdl/utilities/utility.h>

// namespace KDL{

//         Chain Diana(){
       
//         Chain diana;
//         double a4 = 0.065;
//         double a5 = -0.0528;
//         double a6 = -0.0122;
//         double a7 = 0.087;

//         double d1 = -0.2856;
//         double d3 = -0.4586;
//         double d5 = -0.4554;
//         double d7 = -0.1169;

//         double alpha1 = M_PI;
//         double alpha2 = M_PI_2;
//         double alpha3 = -M_PI_2;
//         double alpha4 = M_PI_2;
//         double alpha5 = -M_PI_2;
//         double alpha6 = -M_PI_2;
//         double alpha7 = -M_PI_2;

//         double theta6 = M_PI;

//         diana.addSegment(Segment("base_link", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha1), sin(alpha1)),
//                                                     Vector(0, -sin(alpha1), cos(alpha1))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(0,0,d1))));
//         diana.addSegment(Segment("joint1",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link1", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha2), sin(alpha2)),
//                                                     Vector(0, -sin(alpha2), cos(alpha2))))));
//         diana.addSegment(Segment("joint2",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link2", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha3), sin(alpha3)),
//                                                     Vector(0, -sin(alpha3), cos(alpha3))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(0,0,d3))));
//         diana.addSegment(Segment("joint3",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link3", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha4), sin(alpha4)),
//                                                     Vector(0, -sin(alpha4), cos(alpha4))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a4,0,0))));
//         diana.addSegment(Segment("joint4",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link4", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha5), sin(alpha5)),
//                                                     Vector(0, -sin(alpha5), cos(alpha5))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a5,0,d5))));
//         diana.addSegment(Segment("joint5",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link5", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha6), sin(alpha6)),
//                                                     Vector(0, -sin(alpha6), cos(alpha6))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a6,0,0))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Rotation(
//                                                     Vector(cos(theta6), -sin(theta6), 0),
//                                                     Vector(sin(theta6), cos(theta6), 0),
//                                                     Vector(0, 0, 1)))));
//         diana.addSegment(Segment("joint6",Joint(Joint::RotZ)));

//         diana.addSegment(Segment("link6", Joint(Joint::None), 
//                                                 Frame(Rotation(
//                                                     Vector(1, 0, 0),
//                                                     Vector(0, cos(alpha7), sin(alpha7)),
//                                                     Vector(0, -sin(alpha7), cos(alpha7))))));
//         diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a7,0,d7))));
//         diana.addSegment(Segment("joint7",Joint(Joint::RotZ)));

//         return diana;
//     }
// }
// #endif //DIANA_MODEL_HPP

#ifndef DIANA_MODEL_HPP
#define DIANA_MODEL_HPP

#include <kdl/chain.hpp>
#include <kdl/utilities/utility.h>

namespace KDL{

        Chain Diana(){
       
        Chain diana;
        double a4 = 0.065;
        double a5 = -0.0528;
        double a6 = 0.000;
        double a7 = 0.077;

        double d1 = -0.2985;
        double d3 = -0.4591;
        double d5 = -0.4574;
        double d6 = -0.0050;
        double d7 = -0.1059;

        double alpha1 = M_PI;
        double alpha2 = M_PI_2;
        double alpha3 = -M_PI_2;
        double alpha4 = M_PI_2;
        double alpha5 = -M_PI_2;
        double alpha6 = -M_PI_2;
        double alpha7 = -M_PI_2;

        double theta6 = M_PI;

        diana.addSegment(Segment("base_link", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha1), sin(alpha1)),
                                                    Vector(0, -sin(alpha1), cos(alpha1))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(0,0,d1))));
        diana.addSegment(Segment("joint1",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link1", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha2), sin(alpha2)),
                                                    Vector(0, -sin(alpha2), cos(alpha2))))));
        diana.addSegment(Segment("joint2",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link2", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha3), sin(alpha3)),
                                                    Vector(0, -sin(alpha3), cos(alpha3))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(0,0,d3))));
        diana.addSegment(Segment("joint3",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link3", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha4), sin(alpha4)),
                                                    Vector(0, -sin(alpha4), cos(alpha4))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a4,0,0))));
        diana.addSegment(Segment("joint4",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link4", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha5), sin(alpha5)),
                                                    Vector(0, -sin(alpha5), cos(alpha5))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a5,0,d5))));
        diana.addSegment(Segment("joint5",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link5", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha6), sin(alpha6)),
                                                    Vector(0, -sin(alpha6), cos(alpha6))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a6,0,d6))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Rotation(
                                                    Vector(cos(theta6), -sin(theta6), 0),
                                                    Vector(sin(theta6), cos(theta6), 0),
                                                    Vector(0, 0, 1)))));
        diana.addSegment(Segment("joint6",Joint(Joint::RotZ)));

        diana.addSegment(Segment("link6", Joint(Joint::None), 
                                                Frame(Rotation(
                                                    Vector(1, 0, 0),
                                                    Vector(0, cos(alpha7), sin(alpha7)),
                                                    Vector(0, -sin(alpha7), cos(alpha7))))));
        diana.addSegment(Segment(Joint(Joint::None), Frame(Vector(a7,0,d7))));
        diana.addSegment(Segment("joint7",Joint(Joint::RotZ)));

        return diana;
    }
}
#endif //DIANA_MODEL_HPP