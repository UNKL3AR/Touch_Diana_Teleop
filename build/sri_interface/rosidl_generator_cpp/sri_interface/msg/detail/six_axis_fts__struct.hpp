// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_HPP_
#define SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__sri_interface__msg__SixAxisFTS __attribute__((deprecated))
#else
# define DEPRECATED__sri_interface__msg__SixAxisFTS __declspec(deprecated)
#endif

namespace sri_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SixAxisFTS_
{
  using Type = SixAxisFTS_<ContainerAllocator>;

  explicit SixAxisFTS_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_force = 0.0f;
      this->y_force = 0.0f;
      this->z_force = 0.0f;
      this->x_torque = 0.0f;
      this->y_torque = 0.0f;
      this->z_torque = 0.0f;
      this->frame_number = 0;
      this->sampling_time = 0.0f;
    }
  }

  explicit SixAxisFTS_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_force = 0.0f;
      this->y_force = 0.0f;
      this->z_force = 0.0f;
      this->x_torque = 0.0f;
      this->y_torque = 0.0f;
      this->z_torque = 0.0f;
      this->frame_number = 0;
      this->sampling_time = 0.0f;
    }
  }

  // field types and members
  using _x_force_type =
    float;
  _x_force_type x_force;
  using _y_force_type =
    float;
  _y_force_type y_force;
  using _z_force_type =
    float;
  _z_force_type z_force;
  using _x_torque_type =
    float;
  _x_torque_type x_torque;
  using _y_torque_type =
    float;
  _y_torque_type y_torque;
  using _z_torque_type =
    float;
  _z_torque_type z_torque;
  using _frame_number_type =
    uint16_t;
  _frame_number_type frame_number;
  using _sampling_time_type =
    float;
  _sampling_time_type sampling_time;

  // setters for named parameter idiom
  Type & set__x_force(
    const float & _arg)
  {
    this->x_force = _arg;
    return *this;
  }
  Type & set__y_force(
    const float & _arg)
  {
    this->y_force = _arg;
    return *this;
  }
  Type & set__z_force(
    const float & _arg)
  {
    this->z_force = _arg;
    return *this;
  }
  Type & set__x_torque(
    const float & _arg)
  {
    this->x_torque = _arg;
    return *this;
  }
  Type & set__y_torque(
    const float & _arg)
  {
    this->y_torque = _arg;
    return *this;
  }
  Type & set__z_torque(
    const float & _arg)
  {
    this->z_torque = _arg;
    return *this;
  }
  Type & set__frame_number(
    const uint16_t & _arg)
  {
    this->frame_number = _arg;
    return *this;
  }
  Type & set__sampling_time(
    const float & _arg)
  {
    this->sampling_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    sri_interface::msg::SixAxisFTS_<ContainerAllocator> *;
  using ConstRawPtr =
    const sri_interface::msg::SixAxisFTS_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      sri_interface::msg::SixAxisFTS_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      sri_interface::msg::SixAxisFTS_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__sri_interface__msg__SixAxisFTS
    std::shared_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__sri_interface__msg__SixAxisFTS
    std::shared_ptr<sri_interface::msg::SixAxisFTS_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SixAxisFTS_ & other) const
  {
    if (this->x_force != other.x_force) {
      return false;
    }
    if (this->y_force != other.y_force) {
      return false;
    }
    if (this->z_force != other.z_force) {
      return false;
    }
    if (this->x_torque != other.x_torque) {
      return false;
    }
    if (this->y_torque != other.y_torque) {
      return false;
    }
    if (this->z_torque != other.z_torque) {
      return false;
    }
    if (this->frame_number != other.frame_number) {
      return false;
    }
    if (this->sampling_time != other.sampling_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const SixAxisFTS_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SixAxisFTS_

// alias to use template instance with default allocator
using SixAxisFTS =
  sri_interface::msg::SixAxisFTS_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace sri_interface

#endif  // SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__STRUCT_HPP_
