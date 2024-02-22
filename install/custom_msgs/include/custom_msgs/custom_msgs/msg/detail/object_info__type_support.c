// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msgs:msg/ObjectInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msgs/msg/detail/object_info__rosidl_typesupport_introspection_c.h"
#include "custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msgs/msg/detail/object_info__functions.h"
#include "custom_msgs/msg/detail/object_info__struct.h"


// Include directives for member types
// Member `objects`
#include "custom_msgs/msg/object.h"
// Member `objects`
#include "custom_msgs/msg/detail/object__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msgs__msg__ObjectInfo__init(message_memory);
}

void custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_fini_function(void * message_memory)
{
  custom_msgs__msg__ObjectInfo__fini(message_memory);
}

size_t custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__size_function__ObjectInfo__objects(
  const void * untyped_member)
{
  const custom_msgs__msg__Object__Sequence * member =
    (const custom_msgs__msg__Object__Sequence *)(untyped_member);
  return member->size;
}

const void * custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_const_function__ObjectInfo__objects(
  const void * untyped_member, size_t index)
{
  const custom_msgs__msg__Object__Sequence * member =
    (const custom_msgs__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void * custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_function__ObjectInfo__objects(
  void * untyped_member, size_t index)
{
  custom_msgs__msg__Object__Sequence * member =
    (custom_msgs__msg__Object__Sequence *)(untyped_member);
  return &member->data[index];
}

void custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__fetch_function__ObjectInfo__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const custom_msgs__msg__Object * item =
    ((const custom_msgs__msg__Object *)
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_const_function__ObjectInfo__objects(untyped_member, index));
  custom_msgs__msg__Object * value =
    (custom_msgs__msg__Object *)(untyped_value);
  *value = *item;
}

void custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__assign_function__ObjectInfo__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  custom_msgs__msg__Object * item =
    ((custom_msgs__msg__Object *)
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_function__ObjectInfo__objects(untyped_member, index));
  const custom_msgs__msg__Object * value =
    (const custom_msgs__msg__Object *)(untyped_value);
  *item = *value;
}

bool custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__resize_function__ObjectInfo__objects(
  void * untyped_member, size_t size)
{
  custom_msgs__msg__Object__Sequence * member =
    (custom_msgs__msg__Object__Sequence *)(untyped_member);
  custom_msgs__msg__Object__Sequence__fini(member);
  return custom_msgs__msg__Object__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_member_array[2] = {
  {
    "numbers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__ObjectInfo, numbers),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs__msg__ObjectInfo, objects),  // bytes offset in struct
    NULL,  // default value
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__size_function__ObjectInfo__objects,  // size() function pointer
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_const_function__ObjectInfo__objects,  // get_const(index) function pointer
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__get_function__ObjectInfo__objects,  // get(index) function pointer
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__fetch_function__ObjectInfo__objects,  // fetch(index, &value) function pointer
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__assign_function__ObjectInfo__objects,  // assign(index, value) function pointer
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__resize_function__ObjectInfo__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_members = {
  "custom_msgs__msg",  // message namespace
  "ObjectInfo",  // message name
  2,  // number of fields
  sizeof(custom_msgs__msg__ObjectInfo),
  custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_member_array,  // message members
  custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_type_support_handle = {
  0,
  &custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, ObjectInfo)() {
  custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msgs, msg, Object)();
  if (!custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_type_support_handle.typesupport_identifier) {
    custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &custom_msgs__msg__ObjectInfo__rosidl_typesupport_introspection_c__ObjectInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
