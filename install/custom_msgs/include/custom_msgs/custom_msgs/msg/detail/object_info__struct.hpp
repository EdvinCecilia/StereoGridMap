// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/ObjectInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'objects'
#include "custom_msgs/msg/detail/object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__ObjectInfo __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__ObjectInfo __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectInfo_
{
  using Type = ObjectInfo_<ContainerAllocator>;

  explicit ObjectInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->numbers = 0ul;
    }
  }

  explicit ObjectInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->numbers = 0ul;
    }
  }

  // field types and members
  using _numbers_type =
    uint32_t;
  _numbers_type numbers;
  using _objects_type =
    std::vector<custom_msgs::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::Object_<ContainerAllocator>>>;
  _objects_type objects;

  // setters for named parameter idiom
  Type & set__numbers(
    const uint32_t & _arg)
  {
    this->numbers = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<custom_msgs::msg::Object_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::Object_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::ObjectInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::ObjectInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ObjectInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::ObjectInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__ObjectInfo
    std::shared_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__ObjectInfo
    std::shared_ptr<custom_msgs::msg::ObjectInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectInfo_ & other) const
  {
    if (this->numbers != other.numbers) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectInfo_

// alias to use template instance with default allocator
using ObjectInfo =
  custom_msgs::msg::ObjectInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_HPP_
