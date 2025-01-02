#pragma once

extern "C" typedef enum _FunctionIndex {
    T_FREEDRIVING = 0,
    T_CART_IMPEDANCE = 1,
} function_index_e;

extern "C" typedef enum _FreeDrivingDirection {
    T_ALLOW_X = 0x01,
    T_ALLOW_Y = 0x02,
    T_ALLOW_Z = 0x04,
    T_ALLOW_XYZ = 0x07,
    T_ALLOW_RX = 0x10,
    T_ALLOW_RY = 0x20,
    T_ALLOW_RZ = 0x40,
    T_ALLOW_RXYZ = 0x70,
} free_driving_direction_e;

extern "C" typedef enum _FunctionBaseName {
    T_DEFAULT_OPT = 0,                      // set only
    T_FREEDRIVING_OPT_OFFSET = 0x10000,     // not used
    T_CART_IMPEDANCE_OPT_OFFSET = 0x10100,  // not used
} function_opt_name_e;

extern "C" typedef enum _FreeDrivingOptName {
    T_ALLOW_DIRECTION = function_opt_name_e::T_FREEDRIVING_OPT_OFFSET,  // not used
    T_ENABLE_ARM_ANGLE,                                                 // read and write
    T_FLOOR_ARM_ANGLE,                                                  // read and write
    T_CEIL_ARM_ANGLE,                                                   // read and write
    T_ENABLE_RESIST_FORCE,                                              // write only
    T_ENABLE_REALTIME_VIRTUAL_WALL = 0x10005,                           // read and write
    T_MAX_TRANSLATION_DECELERATION = 0x10006,                           // read and write
    T_CONTROL_RULE = 0x10008,                                           // read and write
    T_MAX_ALLOWED_MOVE_ZONE = 0x10009,                                  // read and write
    T_MAX_ALLOWED_MOVE_SPEED = 0x1000A,                                 // read and write
} freedriving_opt_name_e;

extern "C" typedef enum _CartImpedanceOptName {
    T_COORDINATE_TYPE = function_opt_name_e::T_CART_IMPEDANCE_OPT_OFFSET,  // read and write
    T_IS_SINGLE_AXIS_LOCKED = 0x10101,                                     // read only
    T_LOCKED_SINGLE_AXIS = 0x10102,                                        // write only
    T_CONSTRAIN_TYPE = 0x10103,                                            // read and write
} cart_impedance_opt_name_e;

extern "C" typedef enum _CollisionLevel {
    T_COLLISION_LEVEL_CLOSE = 0,
    T_COLLISION_JOINT = 0x01,
    T_COLLISION_CART = 0x02,
    T_COLLISION_RESULTANT = 0x04,
}collision_level_e;

#define JOINT_COLLISION_THRESHOLD_MAX    (1000)
#define CART_COLLISION_THRESHOLD_MAX    (1007)
#define RESULTANT_COLLISION_THRESHOLD_MAX    (1013)

extern "C" typedef enum _FrameType {
    T_FRAME_TYPE_NONE = 0,
    T_FRAME_TYPE_BASE = 1,
    T_FRAME_TYPE_TOOL = 2,
    T_FRAME_TYPE_WORKPIECE = 3,
    T_FRAME_TYPE_MAX
}frame_type_e;
