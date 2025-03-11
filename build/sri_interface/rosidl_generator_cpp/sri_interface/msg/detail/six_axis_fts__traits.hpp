// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__TRAITS_HPP_
#define SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sri_interface/msg/detail/six_axis_fts__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace sri_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const SixAxisFTS & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_force
  {
    out << "x_force: ";
    rosidl_generator_traits::value_to_yaml(msg.x_force, out);
    out << ", ";
  }

  // member: y_force
  {
    out << "y_force: ";
    rosidl_generator_traits::value_to_yaml(msg.y_force, out);
    out << ", ";
  }

  // member: z_force
  {
    out << "z_force: ";
    rosidl_generator_traits::value_to_yaml(msg.z_force, out);
    out << ", ";
  }

  // member: x_torque
  {
    out << "x_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.x_torque, out);
    out << ", ";
  }

  // member: y_torque
  {
    out << "y_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.y_torque, out);
    out << ", ";
  }

  // member: z_torque
  {
    out << "z_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.z_torque, out);
    out << ", ";
  }

  // member: frame_number
  {
    out << "frame_number: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_number, out);
    out << ", ";
  }

  // member: sampling_time
  {
    out << "sampling_time: ";
    rosidl_generator_traits::value_to_yaml(msg.sampling_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SixAxisFTS & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_force: ";
    rosidl_generator_traits::value_to_yaml(msg.x_force, out);
    out << "\n";
  }

  // member: y_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_force: ";
    rosidl_generator_traits::value_to_yaml(msg.y_force, out);
    out << "\n";
  }

  // member: z_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_force: ";
    rosidl_generator_traits::value_to_yaml(msg.z_force, out);
    out << "\n";
  }

  // member: x_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.x_torque, out);
    out << "\n";
  }

  // member: y_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.y_torque, out);
    out << "\n";
  }

  // member: z_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_torque: ";
    rosidl_generator_traits::value_to_yaml(msg.z_torque, out);
    out << "\n";
  }

  // member: frame_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frame_number: ";
    rosidl_generator_traits::value_to_yaml(msg.frame_number, out);
    out << "\n";
  }

  // member: sampling_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sampling_time: ";
    rosidl_generator_traits::value_to_yaml(msg.sampling_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SixAxisFTS & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace sri_interface

namespace rosidl_generator_traits
{

[[deprecated("use sri_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const sri_interface::msg::SixAxisFTS & msg,
  std::ostream & out, size_t indentation = 0)
{
  sri_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sri_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const sri_interface::msg::SixAxisFTS & msg)
{
  return sri_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sri_interface::msg::SixAxisFTS>()
{
  return "sri_interface::msg::SixAxisFTS";
}

template<>
inline const char * name<sri_interface::msg::SixAxisFTS>()
{
  return "sri_interface/msg/SixAxisFTS";
}

template<>
struct has_fixed_size<sri_interface::msg::SixAxisFTS>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<sri_interface::msg::SixAxisFTS>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<sri_interface::msg::SixAxisFTS>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__TRAITS_HPP_
