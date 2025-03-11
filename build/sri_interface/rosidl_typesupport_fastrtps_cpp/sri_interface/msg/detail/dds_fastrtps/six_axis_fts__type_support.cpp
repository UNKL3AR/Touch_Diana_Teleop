// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice
#include "sri_interface/msg/detail/six_axis_fts__rosidl_typesupport_fastrtps_cpp.hpp"
#include "sri_interface/msg/detail/six_axis_fts__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace sri_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sri_interface
cdr_serialize(
  const sri_interface::msg::SixAxisFTS & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x_force
  cdr << ros_message.x_force;
  // Member: y_force
  cdr << ros_message.y_force;
  // Member: z_force
  cdr << ros_message.z_force;
  // Member: x_torque
  cdr << ros_message.x_torque;
  // Member: y_torque
  cdr << ros_message.y_torque;
  // Member: z_torque
  cdr << ros_message.z_torque;
  // Member: frame_number
  cdr << ros_message.frame_number;
  // Member: sampling_time
  cdr << ros_message.sampling_time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sri_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  sri_interface::msg::SixAxisFTS & ros_message)
{
  // Member: x_force
  cdr >> ros_message.x_force;

  // Member: y_force
  cdr >> ros_message.y_force;

  // Member: z_force
  cdr >> ros_message.z_force;

  // Member: x_torque
  cdr >> ros_message.x_torque;

  // Member: y_torque
  cdr >> ros_message.y_torque;

  // Member: z_torque
  cdr >> ros_message.z_torque;

  // Member: frame_number
  cdr >> ros_message.frame_number;

  // Member: sampling_time
  cdr >> ros_message.sampling_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sri_interface
get_serialized_size(
  const sri_interface::msg::SixAxisFTS & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x_force
  {
    size_t item_size = sizeof(ros_message.x_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_force
  {
    size_t item_size = sizeof(ros_message.y_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: z_force
  {
    size_t item_size = sizeof(ros_message.z_force);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: x_torque
  {
    size_t item_size = sizeof(ros_message.x_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_torque
  {
    size_t item_size = sizeof(ros_message.y_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: z_torque
  {
    size_t item_size = sizeof(ros_message.z_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: frame_number
  {
    size_t item_size = sizeof(ros_message.frame_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sampling_time
  {
    size_t item_size = sizeof(ros_message.sampling_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_sri_interface
max_serialized_size_SixAxisFTS(
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


  // Member: x_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: z_force
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: x_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: z_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: frame_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: sampling_time
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
    using DataType = sri_interface::msg::SixAxisFTS;
    is_plain =
      (
      offsetof(DataType, sampling_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SixAxisFTS__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const sri_interface::msg::SixAxisFTS *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SixAxisFTS__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<sri_interface::msg::SixAxisFTS *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SixAxisFTS__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const sri_interface::msg::SixAxisFTS *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SixAxisFTS__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SixAxisFTS(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SixAxisFTS__callbacks = {
  "sri_interface::msg",
  "SixAxisFTS",
  _SixAxisFTS__cdr_serialize,
  _SixAxisFTS__cdr_deserialize,
  _SixAxisFTS__get_serialized_size,
  _SixAxisFTS__max_serialized_size
};

static rosidl_message_type_support_t _SixAxisFTS__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SixAxisFTS__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace sri_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_sri_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<sri_interface::msg::SixAxisFTS>()
{
  return &sri_interface::msg::typesupport_fastrtps_cpp::_SixAxisFTS__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, sri_interface, msg, SixAxisFTS)() {
  return &sri_interface::msg::typesupport_fastrtps_cpp::_SixAxisFTS__handle;
}

#ifdef __cplusplus
}
#endif
