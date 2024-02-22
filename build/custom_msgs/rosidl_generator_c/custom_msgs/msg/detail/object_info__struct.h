// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/ObjectInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'objects'
#include "custom_msgs/msg/detail/object__struct.h"

/// Struct defined in msg/ObjectInfo in the package custom_msgs.
typedef struct custom_msgs__msg__ObjectInfo
{
  uint32_t numbers;
  custom_msgs__msg__Object__Sequence objects;
} custom_msgs__msg__ObjectInfo;

// Struct for a sequence of custom_msgs__msg__ObjectInfo.
typedef struct custom_msgs__msg__ObjectInfo__Sequence
{
  custom_msgs__msg__ObjectInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__ObjectInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__OBJECT_INFO__STRUCT_H_
