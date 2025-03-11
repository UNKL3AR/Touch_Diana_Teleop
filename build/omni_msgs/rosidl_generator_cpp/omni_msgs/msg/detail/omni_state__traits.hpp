// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_STATE__TRAITS_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "omni_msgs/msg/detail/omni_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'current'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace omni_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OmniState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: locked
  {
    out << "locked: ";
    rosidl_generator_traits::value_to_yaml(msg.locked, out);
    out << ", ";
  }

  // member: close_gripper
  {
    out << "close_gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.close_gripper, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: current
  {
    out << "current: ";
    to_flow_style_yaml(msg.current, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    to_flow_style_yaml(msg.velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OmniState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: locked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "locked: ";
    rosidl_generator_traits::value_to_yaml(msg.locked, out);
    out << "\n";
  }

  // member: close_gripper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "close_gripper: ";
    rosidl_generator_traits::value_to_yaml(msg.close_gripper, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current:\n";
    to_block_style_yaml(msg.current, out, indentation + 2);
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity:\n";
    to_block_style_yaml(msg.velocity, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OmniState & msg, bool use_flow_style = false)
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

}  // namespace omni_msgs

namespace rosidl_generator_traits
{

[[deprecated("use omni_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omni_msgs::msg::OmniState & msg,
  std::ostream & out, size_t indentation = 0)
{
  omni_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omni_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const omni_msgs::msg::OmniState & msg)
{
  return omni_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<omni_msgs::msg::OmniState>()
{
  return "omni_msgs::msg::OmniState";
}

template<>
inline const char * name<omni_msgs::msg::OmniState>()
{
  return "omni_msgs/msg/OmniState";
}

template<>
struct has_fixed_size<omni_msgs::msg::OmniState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<omni_msgs::msg::OmniState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<omni_msgs::msg::OmniState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_STATE__TRAITS_HPP_
