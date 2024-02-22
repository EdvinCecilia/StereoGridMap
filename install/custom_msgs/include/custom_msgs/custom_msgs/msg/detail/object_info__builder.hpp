// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ObjectInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/object_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjectInfo_objects
{
public:
  explicit Init_ObjectInfo_objects(::custom_msgs::msg::ObjectInfo & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ObjectInfo objects(::custom_msgs::msg::ObjectInfo::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ObjectInfo msg_;
};

class Init_ObjectInfo_numbers
{
public:
  Init_ObjectInfo_numbers()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectInfo_objects numbers(::custom_msgs::msg::ObjectInfo::_numbers_type arg)
  {
    msg_.numbers = std::move(arg);
    return Init_ObjectInfo_objects(msg_);
  }

private:
  ::custom_msgs::msg::ObjectInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ObjectInfo>()
{
  return custom_msgs::msg::builder::Init_ObjectInfo_numbers();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__BUILDER_HPP_
