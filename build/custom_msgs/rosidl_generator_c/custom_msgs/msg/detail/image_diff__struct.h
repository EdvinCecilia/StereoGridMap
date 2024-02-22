// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/ImageDiff.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ImageDiff in the package custom_msgs.
/**
  * ImageDiff.msg, size = width*height*2
 */
typedef struct custom_msgs__msg__ImageDiff
{
  uint32_t width;
  uint32_t height;
  rosidl_runtime_c__uint8__Sequence data;
} custom_msgs__msg__ImageDiff;

// Struct for a sequence of custom_msgs__msg__ImageDiff.
typedef struct custom_msgs__msg__ImageDiff__Sequence
{
  custom_msgs__msg__ImageDiff * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__ImageDiff__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__IMAGE_DIFF__STRUCT_H_
