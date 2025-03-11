// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "omni_msgs/msg/detail/omni_state__struct.h"
#include "omni_msgs/msg/detail/omni_state__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace omni_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _OmniState_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _OmniState_type_support_ids_t;

static const _OmniState_type_support_ids_t _OmniState_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _OmniState_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _OmniState_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _OmniState_type_support_symbol_names_t _OmniState_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, omni_msgs, msg, OmniState)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, omni_msgs, msg, OmniState)),
  }
};

typedef struct _OmniState_type_support_data_t
{
  void * data[2];
} _OmniState_type_support_data_t;

static _OmniState_type_support_data_t _OmniState_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _OmniState_message_typesupport_map = {
  2,
  "omni_msgs",
  &_OmniState_message_typesupport_ids.typesupport_identifier[0],
  &_OmniState_message_typesupport_symbol_names.symbol_name[0],
  &_OmniState_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t OmniState_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_OmniState_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace omni_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, omni_msgs, msg, OmniState)() {
  return &::omni_msgs::msg::rosidl_typesupport_c::OmniState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
