// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_HPP_
#define OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__omni_msgs__msg__OmniButtonEvent __attribute__((deprecated))
#else
# define DEPRECATED__omni_msgs__msg__OmniButtonEvent __declspec(deprecated)
#endif

namespace omni_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OmniButtonEvent_
{
  using Type = OmniButtonEvent_<ContainerAllocator>;

  explicit OmniButtonEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grey_button = 0l;
      this->white_button = 0l;
    }
  }

  explicit OmniButtonEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->grey_button = 0l;
      this->white_button = 0l;
    }
  }

  // field types and members
  using _grey_button_type =
    int32_t;
  _grey_button_type grey_button;
  using _white_button_type =
    int32_t;
  _white_button_type white_button;

  // setters for named parameter idiom
  Type & set__grey_button(
    const int32_t & _arg)
  {
    this->grey_button = _arg;
    return *this;
  }
  Type & set__white_button(
    const int32_t & _arg)
  {
    this->white_button = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__omni_msgs__msg__OmniButtonEvent
    std::shared_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__omni_msgs__msg__OmniButtonEvent
    std::shared_ptr<omni_msgs::msg::OmniButtonEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OmniButtonEvent_ & other) const
  {
    if (this->grey_button != other.grey_button) {
      return false;
    }
    if (this->white_button != other.white_button) {
      return false;
    }
    return true;
  }
  bool operator!=(const OmniButtonEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OmniButtonEvent_

// alias to use template instance with default allocator
using OmniButtonEvent =
  omni_msgs::msg::OmniButtonEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace omni_msgs

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__STRUCT_HPP_
