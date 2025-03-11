// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_H_
#define OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'current'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/OmniState in the package omni_msgs.
typedef struct omni_msgs__msg__OmniState
{
  std_msgs__msg__Header header;
  bool locked;
  bool close_gripper;
  /// meters
  geometry_msgs__msg__Pose pose;
  /// Amperes
  geometry_msgs__msg__Vector3 current;
  /// meters/s
  geometry_msgs__msg__Vector3 velocity;
} omni_msgs__msg__OmniState;

// Struct for a sequence of omni_msgs__msg__OmniState.
typedef struct omni_msgs__msg__OmniState__Sequence
{
  omni_msgs__msg__OmniState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omni_msgs__msg__OmniState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_H_
