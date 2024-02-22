// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ImageNv12.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__IMAGE_NV12__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__IMAGE_NV12__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/image_nv12__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ImageNv12_data
{
public:
  explicit Init_ImageNv12_data(::custom_msgs::msg::ImageNv12 & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ImageNv12 data(::custom_msgs::msg::ImageNv12::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ImageNv12 msg_;
};

class Init_ImageNv12_height
{
public:
  explicit Init_ImageNv12_height(::custom_msgs::msg::ImageNv12 & msg)
  : msg_(msg)
  {}
  Init_ImageNv12_data height(::custom_msgs::msg::ImageNv12::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageNv12_data(msg_);
  }

private:
  ::custom_msgs::msg::ImageNv12 msg_;
};

class Init_ImageNv12_width
{
public:
  Init_ImageNv12_width()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageNv12_height width(::custom_msgs::msg::ImageNv12::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageNv12_height(msg_);
  }

private:
  ::custom_msgs::msg::ImageNv12 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ImageNv12>()
{
  return custom_msgs::msg::builder::Init_ImageNv12_width();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__IMAGE_NV12__BUILDER_HPP_
