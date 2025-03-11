// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omni_msgs:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omni_msgs/msg/detail/omni_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omni_msgs
{

namespace msg
{

namespace builder
{

class Init_OmniFeedback_position
{
public:
  explicit Init_OmniFeedback_position(::omni_msgs::msg::OmniFeedback & msg)
  : msg_(msg)
  {}
  ::omni_msgs::msg::OmniFeedback position(::omni_msgs::msg::OmniFeedback::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omni_msgs::msg::OmniFeedback msg_;
};

class Init_OmniFeedback_force
{
public:
  Init_OmniFeedback_force()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OmniFeedback_position force(::omni_msgs::msg::OmniFeedback::_force_type arg)
  {
    msg_.force = std::move(arg);
    return Init_OmniFeedback_position(msg_);
  }

private:
  ::omni_msgs::msg::OmniFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omni_msgs::msg::OmniFeedback>()
{
  return omni_msgs::msg::builder::Init_OmniFeedback_force();
}

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__BUILDER_HPP_
