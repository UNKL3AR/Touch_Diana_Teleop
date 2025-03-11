// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__BUILDER_HPP_
#define SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "sri_interface/msg/detail/six_axis_fts__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace sri_interface
{

namespace msg
{

namespace builder
{

class Init_SixAxisFTS_sampling_time
{
public:
  explicit Init_SixAxisFTS_sampling_time(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  ::sri_interface::msg::SixAxisFTS sampling_time(::sri_interface::msg::SixAxisFTS::_sampling_time_type arg)
  {
    msg_.sampling_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_frame_number
{
public:
  explicit Init_SixAxisFTS_frame_number(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_sampling_time frame_number(::sri_interface::msg::SixAxisFTS::_frame_number_type arg)
  {
    msg_.frame_number = std::move(arg);
    return Init_SixAxisFTS_sampling_time(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_z_torque
{
public:
  explicit Init_SixAxisFTS_z_torque(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_frame_number z_torque(::sri_interface::msg::SixAxisFTS::_z_torque_type arg)
  {
    msg_.z_torque = std::move(arg);
    return Init_SixAxisFTS_frame_number(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_y_torque
{
public:
  explicit Init_SixAxisFTS_y_torque(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_z_torque y_torque(::sri_interface::msg::SixAxisFTS::_y_torque_type arg)
  {
    msg_.y_torque = std::move(arg);
    return Init_SixAxisFTS_z_torque(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_x_torque
{
public:
  explicit Init_SixAxisFTS_x_torque(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_y_torque x_torque(::sri_interface::msg::SixAxisFTS::_x_torque_type arg)
  {
    msg_.x_torque = std::move(arg);
    return Init_SixAxisFTS_y_torque(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_z_force
{
public:
  explicit Init_SixAxisFTS_z_force(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_x_torque z_force(::sri_interface::msg::SixAxisFTS::_z_force_type arg)
  {
    msg_.z_force = std::move(arg);
    return Init_SixAxisFTS_x_torque(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_y_force
{
public:
  explicit Init_SixAxisFTS_y_force(::sri_interface::msg::SixAxisFTS & msg)
  : msg_(msg)
  {}
  Init_SixAxisFTS_z_force y_force(::sri_interface::msg::SixAxisFTS::_y_force_type arg)
  {
    msg_.y_force = std::move(arg);
    return Init_SixAxisFTS_z_force(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

class Init_SixAxisFTS_x_force
{
public:
  Init_SixAxisFTS_x_force()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SixAxisFTS_y_force x_force(::sri_interface::msg::SixAxisFTS::_x_force_type arg)
  {
    msg_.x_force = std::move(arg);
    return Init_SixAxisFTS_y_force(msg_);
  }

private:
  ::sri_interface::msg::SixAxisFTS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::sri_interface::msg::SixAxisFTS>()
{
  return sri_interface::msg::builder::Init_SixAxisFTS_x_force();
}

}  // namespace sri_interface

#endif  // SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__BUILDER_HPP_
