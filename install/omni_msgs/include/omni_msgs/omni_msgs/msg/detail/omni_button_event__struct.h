// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_H_
#define OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/OmniButtonEvent in the package omni_msgs.
typedef struct omni_msgs__msg__OmniButtonEvent
{
  int32_t grey_button;
  int32_t white_button;
} omni_msgs__msg__OmniButtonEvent;

// Struct for a sequence of omni_msgs__msg__OmniButtonEvent.
typedef struct omni_msgs__msg__OmniButtonEvent__Sequence
{
  omni_msgs__msg__OmniButtonEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omni_msgs__msg__OmniButtonEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_H_
