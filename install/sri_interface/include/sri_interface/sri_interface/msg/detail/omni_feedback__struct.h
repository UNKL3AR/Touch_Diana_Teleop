// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sri_interface:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_
#define SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_

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

/// Struct defined in msg/OmniFeedback in the package sri_interface.
typedef struct sri_interface__msg__OmniFeedback
{
  geometry_msgs__msg__Vector3 force;
  geometry_msgs__msg__Vector3 position;
} sri_interface__msg__OmniFeedback;

// Struct for a sequence of sri_interface__msg__OmniFeedback.
typedef struct sri_interface__msg__OmniFeedback__Sequence
{
  sri_interface__msg__OmniFeedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sri_interface__msg__OmniFeedback__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_H_
