// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice
#include "sri_interface/msg/detail/six_axis_fts__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "sri_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "sri_interface/msg/detail/six_axis_fts__struct.h"
#include "sri_interface/msg/detail/six_axis_fts__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SixAxisFTS__ros_msg_type = sri_interface__msg__SixAxisFTS;

static bool _SixAxisFTS__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SixAxisFTS__ros_msg_type * ros_message = static_cast<const _SixAxisFTS__ros_msg_type *>(untyped_ros_message);
  // Field name: x_force
  {
    cdr << ros_message->x_force;
  }

  // Field name: y_force
  {
    cdr << ros_message->y_force;
  }

  // Field name: z_force
  {
    cdr << ros_message->z_force;
  }

  // Field name: x_torque
  {
    cdr << ros_message->x_torque;
  }

  // Field name: y_torque
  {
    cdr << ros_message->y_torque;
  }

  // Field name: z_torque
  {
    cdr << ros_message->z_torque;
  }

  // Field name: frame_number
  {
    cdr << ros_message->frame_number;
  }

  // Field name: sampling_time
  {
    cdr << ros_message->sampling_time;
  }

  return true;
}

static bool _SixAxisFTS__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SixAxisFTS__ros_msg_type * ros_message = static_cast<_SixAxisFTS__ros_msg_type *>(untyped_ros_message);
  // Field name: x_force
  {
    cdr >> ros_message->x_force;
  }

  // Field name: y_force
  {
    cdr >> ros_message->y_force;
  }

  // Field name: z_force
  {
    cdr >> ros_message->z_force;
  }

  // Field name: x_torque
  {
    cdr >> ros_message->x_torque;
  }

  // Field name: y_torque
  {
    cdr >> ros_message->y_torque;
  }

  // Field name: z_torque
  {
    cdr >> ros_message->z_torque;
  }

  // Field name: frame_number
  {
    cdr >> ros_message->frame_number;
  }

  // Field name: sampling_time
  {
    cdr >> ros_message->sampling_time;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sri_interface
size_t get_serialized_size_sri_interface__msg__SixAxisFTS(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SixAxisFTS__ros_msg_type * ros_message = static_cast<const _SixAxisFTS__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x_force
  {
    size_t item_size = sizeof(ros_message->x_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_force
  {
    size_t item_size = sizeof(ros_message->y_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name z_force
  {
    size_t item_size = sizeof(ros_message->z_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_torque
  {
    size_t item_size = sizeof(ros_message->x_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_torque
  {
    size_t item_size = sizeof(ros_message->y_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name z_torque
  {
    size_t item_size = sizeof(ros_message->z_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name frame_number
  {
    size_t item_size = sizeof(ros_message->frame_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sampling_time
  {
    size_t item_size = sizeof(ros_message->sampling_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SixAxisFTS__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_sri_interface__msg__SixAxisFTS(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_sri_interface
size_t max_serialized_size_sri_interface__msg__SixAxisFTS(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: x_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: z_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: z_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: frame_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sampling_time
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = sri_interface__msg__SixAxisFTS;
    is_plain =
      (
      offsetof(DataType, sampling_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SixAxisFTS__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_sri_interface__msg__SixAxisFTS(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SixAxisFTS = {
  "sri_interface::msg",
  "SixAxisFTS",
  _SixAxisFTS__cdr_serialize,
  _SixAxisFTS__cdr_deserialize,
  _SixAxisFTS__get_serialized_size,
  _SixAxisFTS__max_serialized_size
};

static rosidl_message_type_support_t _SixAxisFTS__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SixAxisFTS,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sri_interface, msg, SixAxisFTS)() {
  return &_SixAxisFTS__type_support;
}

#if defined(__cplusplus)
}
#endif
