// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_STATE__BUILDER_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omni_msgs/msg/detail/omni_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omni_msgs
{

namespace msg
{

namespace builder
{

class Init_OmniState_velocity
{
public:
  explicit Init_OmniState_velocity(::omni_msgs::msg::OmniState & msg)
  : msg_(msg)
  {}
  ::omni_msgs::msg::OmniState velocity(::omni_msgs::msg::OmniState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

class Init_OmniState_current
{
public:
  explicit Init_OmniState_current(::omni_msgs::msg::OmniState & msg)
  : msg_(msg)
  {}
  Init_OmniState_velocity current(::omni_msgs::msg::OmniState::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_OmniState_velocity(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

class Init_OmniState_pose
{
public:
  explicit Init_OmniState_pose(::omni_msgs::msg::OmniState & msg)
  : msg_(msg)
  {}
  Init_OmniState_current pose(::omni_msgs::msg::OmniState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_OmniState_current(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

class Init_OmniState_close_gripper
{
public:
  explicit Init_OmniState_close_gripper(::omni_msgs::msg::OmniState & msg)
  : msg_(msg)
  {}
  Init_OmniState_pose close_gripper(::omni_msgs::msg::OmniState::_close_gripper_type arg)
  {
    msg_.close_gripper = std::move(arg);
    return Init_OmniState_pose(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

class Init_OmniState_locked
{
public:
  explicit Init_OmniState_locked(::omni_msgs::msg::OmniState & msg)
  : msg_(msg)
  {}
  Init_OmniState_close_gripper locked(::omni_msgs::msg::OmniState::_locked_type arg)
  {
    msg_.locked = std::move(arg);
    return Init_OmniState_close_gripper(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

class Init_OmniState_header
{
public:
  Init_OmniState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OmniState_locked header(::omni_msgs::msg::OmniState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OmniState_locked(msg_);
  }

private:
  ::omni_msgs::msg::OmniState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::omni_msgs::msg::OmniState>()
{
  return omni_msgs::msg::builder::Init_OmniState_header();
}

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_STATE__BUILDER_HPP_
