// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omni_msgs:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_
#define OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'force'
// Member 'position'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/OmniFeedback in the package omni_msgs.
typedef struct omni_msgs__msg__OmniFeedback
{
  geometry_msgs__msg__Vector3 force;
  geometry_msgs__msg__Vector3 position;
} omni_msgs__msg__OmniFeedback;

// Struct for a sequence of omni_msgs__msg__OmniFeedback.
typedef struct omni_msgs__msg__OmniFeedback__Sequence
{
  omni_msgs__msg__OmniFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omni_msgs__msg__OmniFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_
