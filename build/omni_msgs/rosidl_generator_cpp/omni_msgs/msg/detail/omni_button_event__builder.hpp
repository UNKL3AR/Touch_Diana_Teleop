// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__BUILDER_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omni_msgs/msg/detail/omni_button_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omni_msgs
{

namespace msg
{

namespace builder
{

class Init_OmniButtonEvent_white_button
{
public:
  explicit Init_OmniButtonEvent_white_button(::omni_msgs::msg::OmniButtonEvent & msg)
  : msg_(msg)
  {}
  ::omni_msgs::msg::OmniButtonEvent white_button(::omni_msgs::msg::OmniButtonEvent::_white_button_type arg)
  {
    msg_.white_button = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omni_msgs::msg::OmniButtonEvent msg_;
};

class Init_OmniButtonEvent_grey_button
{
public:
  Init_OmniButtonEvent_grey_button()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OmniButtonEvent_white_button grey_button(::omni_msgs::msg::OmniButtonEvent::_grey_button_type arg)
  {
    msg_.grey_button = std::move(arg);
    return Init_OmniButtonEvent_white_button(msg_);
  }

private:
  ::omni_msgs::msg::OmniButtonEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omni_msgs::msg::OmniButtonEvent>()
{
  return omni_msgs::msg::builder::Init_OmniButtonEvent_grey_button();
}

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__BUILDER_HPP_
