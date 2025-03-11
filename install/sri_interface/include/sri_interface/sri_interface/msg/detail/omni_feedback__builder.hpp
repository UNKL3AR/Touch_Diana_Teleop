// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sri_interface:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_
#define SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sri_interface/msg/detail/omni_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sri_interface
{

namespace msg
{

namespace builder
{

class Init_OmniFeedback_position
{
public:
  explicit Init_OmniFeedback_position(::sri_interface::msg::OmniFeedback & msg)
  : msg_(msg)
  {}
  ::sri_interface::msg::OmniFeedback position(::sri_interface::msg::OmniFeedback::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sri_interface::msg::OmniFeedback msg_;
};

class Init_OmniFeedback_force
{
public:
  Init_OmniFeedback_force()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OmniFeedback_position force(::sri_interface::msg::OmniFeedback::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_OmniFeedback_position(msg_);
  }

private:
  ::sri_interface::msg::OmniFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sri_interface::msg::OmniFeedback>()
{
  return sri_interface::msg::builder::Init_OmniFeedback_force();
}

}  // namespace sri_interface

#endif  // SRI_INTERFACE__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_
