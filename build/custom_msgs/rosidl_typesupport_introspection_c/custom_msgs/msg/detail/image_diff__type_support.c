// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msgs:msg/ImageDiff.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msgs/msg/detail/image_diff__rosidl_typesupport_introspection_c.h"
#include "custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msgs/msg/detail/image_diff__functions.h"
#include "custom_msgs/msg/detail/image_diff__struct.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msgs__msg__ImageDiff__init(message_memory);
}

void custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_fini_function(void * message_memory)
{
  custom_msgs__msg__ImageDiff__fini(message_memory);
}

size_t custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__size_function__ImageDiff__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_const_function__ImageDiff__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__uint8__Sequence * member =
    (const rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_function__ImageDiff__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__fetch_function__ImageDiff__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint8_t * item =
    ((const uint8_t *)
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_const_function__ImageDiff__data(untyped_member, index));
  uint8_t * value =
    (uint8_t *)(untyped_value);
  *value = *item;
}

void custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__assign_function__ImageDiff__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint8_t * item =
    ((uint8_t *)
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_function__ImageDiff__data(untyped_member, index));
  const uint8_t * value =
    (const uint8_t *)(untyped_value);
  *item = *value;
}

bool custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__resize_function__ImageDiff__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__uint8__Sequence * member =
    (rosidl_runtime_c__uint8__Sequence *)(untyped_member);
  rosidl_runtime_c__uint8__Sequence__fini(member);
  return rosidl_runtime_c__uint8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_member_array[3] = {
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__ImageDiff, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__ImageDiff, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__ImageDiff, data),  // bytes offset in struct
    NULL,  // default value
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__size_function__ImageDiff__data,  // size() function pointer
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_const_function__ImageDiff__data,  // get_const(index) function pointer
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__get_function__ImageDiff__data,  // get(index) function pointer
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__fetch_function__ImageDiff__data,  // fetch(index, &value) function pointer
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__assign_function__ImageDiff__data,  // assign(index, value) function pointer
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__resize_function__ImageDiff__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_members = {
  "custom_msgs__msg",  // message namespace
  "ImageDiff",  // message name
  3,  // number of fields
  sizeof(custom_msgs__msg__ImageDiff),
  custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_member_array,  // message members
  custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_type_support_handle = {
  0,
  &custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, ImageDiff)() {
  if (!custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_type_support_handle.typesupport_identifier) {
    custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msgs__msg__ImageDiff__rosidl_typesupport_introspection_c__ImageDiff_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif