// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_H_
#define SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SixAxisFTS in the package sri_interface.
typedef struct sri_interface__msg__SixAxisFTS
{
  float x_force;
  float y_force;
  float z_force;
  float x_torque;
  float y_torque;
  float z_torque;
  uint16_t frame_number;
  float sampling_time;
} sri_interface__msg__SixAxisFTS;

// Struct for a sequence of sri_interface__msg__SixAxisFTS.
typedef struct sri_interface__msg__SixAxisFTS__Sequence
{
  sri_interface__msg__SixAxisFTS * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} sri_interface__msg__SixAxisFTS__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_H_
