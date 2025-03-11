// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'current'
// Member 'velocity'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__omni_msgs__msg__OmniState __attribute__((deprecated))
#else
# define DEPRECATED__omni_msgs__msg__OmniState __declspec(deprecated)
#endif

namespace omni_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OmniState_
{
  using Type = OmniState_<ContainerAllocator>;

  explicit OmniState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init),
    current(_init),
    velocity(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->close_gripper = false;
    }
  }

  explicit OmniState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose(_alloc, _init),
    current(_alloc, _init),
    velocity(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->locked = false;
      this->close_gripper = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _locked_type =
    bool;
  _locked_type locked;
  using _close_gripper_type =
    bool;
  _close_gripper_type close_gripper;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _current_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _current_type current;
  using _velocity_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _velocity_type velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__locked(
    const bool & _arg)
  {
    this->locked = _arg;
    return *this;
  }
  Type & set__close_gripper(
    const bool & _arg)
  {
    this->close_gripper = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__current(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__velocity(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    omni_msgs::msg::OmniState_<ContainerAllocator> *;
  using ConstRawPtr =
    const omni_msgs::msg::OmniState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__omni_msgs__msg__OmniState
    std::shared_ptr<omni_msgs::msg::OmniState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__omni_msgs__msg__OmniState
    std::shared_ptr<omni_msgs::msg::OmniState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OmniState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->locked != other.locked) {
      return false;
    }
    if (this->close_gripper != other.close_gripper) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const OmniState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OmniState_

// alias to use template instance with default allocator
using OmniState =
  omni_msgs::msg::OmniState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_STATE__STRUCT_HPP_
