// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/ObjectInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/object_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'objects'
#include "custom_msgs/msg/detail/object__traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: numbers
  {
    out << "numbers: ";
    rosidl_generator_traits::value_to_yaml(msg.numbers, out);
    out << ", ";
  }

  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: numbers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "numbers: ";
    rosidl_generator_traits::value_to_yaml(msg.numbers, out);
    out << "\n";
  }

  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::ObjectInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::ObjectInfo & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::ObjectInfo>()
{
  return "custom_msgs::msg::ObjectInfo";
}

template<>
inline const char * name<custom_msgs::msg::ObjectInfo>()
{
  return "custom_msgs/msg/ObjectInfo";
}

template<>
struct has_fixed_size<custom_msgs::msg::ObjectInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::ObjectInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::ObjectInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__TRAITS_HPP_
