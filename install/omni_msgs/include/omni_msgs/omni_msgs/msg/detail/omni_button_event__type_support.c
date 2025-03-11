// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "omni_msgs/msg/detail/omni_button_event__rosidl_typesupport_introspection_c.h"
#include "omni_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "omni_msgs/msg/detail/omni_button_event__functions.h"
#include "omni_msgs/msg/detail/omni_button_event__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  omni_msgs__msg__OmniButtonEvent__init(message_memory);
}

void omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_fini_function(void * message_memory)
{
  omni_msgs__msg__OmniButtonEvent__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_member_array[2] = {
  {
    "grey_button",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omni_msgs__msg__OmniButtonEvent, grey_button),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "white_button",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(omni_msgs__msg__OmniButtonEvent, white_button),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_members = {
  "omni_msgs__msg",  // message namespace
  "OmniButtonEvent",  // message name
  2,  // number of fields
  sizeof(omni_msgs__msg__OmniButtonEvent),
  omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_member_array,  // message members
  omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_init_function,  // function to initialize message memory (memory has to be allocated)
  omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_type_support_handle = {
  0,
  &omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_omni_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, omni_msgs, msg, OmniButtonEvent)() {
  if (!omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_type_support_handle.typesupport_identifier) {
    omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &omni_msgs__msg__OmniButtonEvent__rosidl_typesupport_introspection_c__OmniButtonEvent_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
