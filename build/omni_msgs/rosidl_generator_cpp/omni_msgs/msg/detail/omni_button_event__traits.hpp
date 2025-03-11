// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__TRAITS_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "omni_msgs/msg/detail/omni_button_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace omni_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OmniButtonEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: grey_button
  {
    out << "grey_button: ";
    rosidl_generator_traits::value_to_yaml(msg.grey_button, out);
    out << ", ";
  }

  // member: white_button
  {
    out << "white_button: ";
    rosidl_generator_traits::value_to_yaml(msg.white_button, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OmniButtonEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: grey_button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grey_button: ";
    rosidl_generator_traits::value_to_yaml(msg.grey_button, out);
    out << "\n";
  }

  // member: white_button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "white_button: ";
    rosidl_generator_traits::value_to_yaml(msg.white_button, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OmniButtonEvent & msg, bool use_flow_style = false)
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
  const omni_msgs::msg::OmniButtonEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  omni_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omni_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const omni_msgs::msg::OmniButtonEvent & msg)
{
  return omni_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<omni_msgs::msg::OmniButtonEvent>()
{
  return "omni_msgs::msg::OmniButtonEvent";
}

template<>
inline const char * name<omni_msgs::msg::OmniButtonEvent>()
{
  return "omni_msgs/msg/OmniButtonEvent";
}

template<>
struct has_fixed_size<omni_msgs::msg::OmniButtonEvent>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<omni_msgs::msg::OmniButtonEvent>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<omni_msgs::msg::OmniButtonEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__TRAITS_HPP_
