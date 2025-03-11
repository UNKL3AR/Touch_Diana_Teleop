// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from omni_msgs:msg/OmniFeedback.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'force'
// Member 'position'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__omni_msgs__msg__OmniFeedback __attribute__((deprecated))
#else
# define DEPRECATED__omni_msgs__msg__OmniFeedback __declspec(deprecated)
#endif

namespace omni_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OmniFeedback_
{
  using Type = OmniFeedback_<ContainerAllocator>;

  explicit OmniFeedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : force(_init),
    position(_init)
  {
    (void)_init;
  }

  explicit OmniFeedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : force(_alloc, _init),
    position(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _force_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _force_type force;
  using _position_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _position_type position;

  // setters for named parameter idiom
  Type & set__force(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->force = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    omni_msgs::msg::OmniFeedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const omni_msgs::msg::OmniFeedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniFeedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniFeedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__omni_msgs__msg__OmniFeedback
    std::shared_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__omni_msgs__msg__OmniFeedback
    std::shared_ptr<omni_msgs::msg::OmniFeedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OmniFeedback_ & other) const
  {
    if (this->force != other.force) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const OmniFeedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OmniFeedback_

// alias to use template instance with default allocator
using OmniFeedback =
  omni_msgs::msg::OmniFeedback_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_FEEDBACK__STRUCT_HPP_
