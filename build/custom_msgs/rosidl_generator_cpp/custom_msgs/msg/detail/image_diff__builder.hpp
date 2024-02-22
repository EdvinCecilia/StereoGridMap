// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/ImageDiff.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/image_diff__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_ImageDiff_data
{
public:
  explicit Init_ImageDiff_data(::custom_msgs::msg::ImageDiff & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::ImageDiff data(::custom_msgs::msg::ImageDiff::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::ImageDiff msg_;
};

class Init_ImageDiff_height
{
public:
  explicit Init_ImageDiff_height(::custom_msgs::msg::ImageDiff & msg)
  : msg_(msg)
  {}
  Init_ImageDiff_data height(::custom_msgs::msg::ImageDiff::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ImageDiff_data(msg_);
  }

private:
  ::custom_msgs::msg::ImageDiff msg_;
};

class Init_ImageDiff_width
{
public:
  Init_ImageDiff_width()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ImageDiff_height width(::custom_msgs::msg::ImageDiff::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ImageDiff_height(msg_);
  }

private:
  ::custom_msgs::msg::ImageDiff msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::ImageDiff>()
{
  return custom_msgs::msg::builder::Init_ImageDiff_width();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__BUILDER_HPP_
