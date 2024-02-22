// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/Object.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/object__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_Object_class_id
{
public:
  explicit Init_Object_class_id(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::Object class_id(::custom_msgs::msg::Object::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_prob
{
public:
  explicit Init_Object_prob(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_class_id prob(::custom_msgs::msg::Object::_prob_type arg)
  {
    msg_.prob = std::move(arg);
    return Init_Object_class_id(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_depth
{
public:
  explicit Init_Object_depth(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_prob depth(::custom_msgs::msg::Object::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_Object_prob(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_width
{
public:
  explicit Init_Object_width(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_depth width(::custom_msgs::msg::Object::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_Object_depth(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_length
{
public:
  explicit Init_Object_length(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_width length(::custom_msgs::msg::Object::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_Object_width(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_y
{
public:
  explicit Init_Object_y(::custom_msgs::msg::Object & msg)
  : msg_(msg)
  {}
  Init_Object_length y(::custom_msgs::msg::Object::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Object_length(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

class Init_Object_x
{
public:
  Init_Object_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Object_y x(::custom_msgs::msg::Object::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Object_y(msg_);
  }

private:
  ::custom_msgs::msg::Object msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::Object>()
{
  return custom_msgs::msg::builder::Init_Object_x();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT__BUILDER_HPP_
