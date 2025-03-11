// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from sri_interface:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__TRAITS_HPP_
#define SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "sri_interface/msg/detail/omni_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'force'
// Member 'position'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace sri_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const OmniFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: force
  {
    out << "force: ";
    to_flow_style_yaml(msg.force, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OmniFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force:\n";
    to_block_style_yaml(msg.force, out, indentation + 2);
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OmniFeedback & msg, bool use_flow_style = false)
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
  const sri_interface::msg::OmniFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  sri_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use sri_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const sri_interface::msg::OmniFeedback & msg)
{
  return sri_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<sri_interface::msg::OmniFeedback>()
{
  return "sri_interface::msg::OmniFeedback";
}

template<>
inline const char * name<sri_interface::msg::OmniFeedback>()
{
  return "sri_interface/msg/OmniFeedback";
}

template<>
struct has_fixed_size<sri_interface::msg::OmniFeedback>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<sri_interface::msg::OmniFeedback>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<sri_interface::msg::OmniFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__TRAITS_HPP_
