// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from omni_msgs:msg/OmniState.idl
// generated code does not contain a copyright notice
#include "omni_msgs/msg/detail/omni_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `current`
// Member `velocity`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
omni_msgs__msg__OmniState__init(omni_msgs__msg__OmniState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    omni_msgs__msg__OmniState__fini(msg);
    return false;
  }
  // locked
  // close_gripper
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    omni_msgs__msg__OmniState__fini(msg);
    return false;
  }
  // current
  if (!geometry_msgs__msg__Vector3__init(&msg->current)) {
    omni_msgs__msg__OmniState__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__init(&msg->velocity)) {
    omni_msgs__msg__OmniState__fini(msg);
    return false;
  }
  return true;
}

void
omni_msgs__msg__OmniState__fini(omni_msgs__msg__OmniState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // locked
  // close_gripper
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // current
  geometry_msgs__msg__Vector3__fini(&msg->current);
  // velocity
  geometry_msgs__msg__Vector3__fini(&msg->velocity);
}

bool
omni_msgs__msg__OmniState__are_equal(const omni_msgs__msg__OmniState * lhs, const omni_msgs__msg__OmniState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // locked
  if (lhs->locked != rhs->locked) {
    return false;
  }
  // close_gripper
  if (lhs->close_gripper != rhs->close_gripper) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // current
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->current), &(rhs->current)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  return true;
}

bool
omni_msgs__msg__OmniState__copy(
  const omni_msgs__msg__OmniState * input,
  omni_msgs__msg__OmniState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // locked
  output->locked = input->locked;
  // close_gripper
  output->close_gripper = input->close_gripper;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // current
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->current), &(output->current)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  return true;
}

omni_msgs__msg__OmniState *
omni_msgs__msg__OmniState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniState * msg = (omni_msgs__msg__OmniState *)allocator.allocate(sizeof(omni_msgs__msg__OmniState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(omni_msgs__msg__OmniState));
  bool success = omni_msgs__msg__OmniState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
omni_msgs__msg__OmniState__destroy(omni_msgs__msg__OmniState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    omni_msgs__msg__OmniState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
omni_msgs__msg__OmniState__Sequence__init(omni_msgs__msg__OmniState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniState * data = NULL;

  if (size) {
    data = (omni_msgs__msg__OmniState *)allocator.zero_allocate(size, sizeof(omni_msgs__msg__OmniState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = omni_msgs__msg__OmniState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        omni_msgs__msg__OmniState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
omni_msgs__msg__OmniState__Sequence__fini(omni_msgs__msg__OmniState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      omni_msgs__msg__OmniState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

omni_msgs__msg__OmniState__Sequence *
omni_msgs__msg__OmniState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniState__Sequence * array = (omni_msgs__msg__OmniState__Sequence *)allocator.allocate(sizeof(omni_msgs__msg__OmniState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = omni_msgs__msg__OmniState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
omni_msgs__msg__OmniState__Sequence__destroy(omni_msgs__msg__OmniState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    omni_msgs__msg__OmniState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
omni_msgs__msg__OmniState__Sequence__are_equal(const omni_msgs__msg__OmniState__Sequence * lhs, const omni_msgs__msg__OmniState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!omni_msgs__msg__OmniState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
omni_msgs__msg__OmniState__Sequence__copy(
  const omni_msgs__msg__OmniState__Sequence * input,
  omni_msgs__msg__OmniState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(omni_msgs__msg__OmniState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    omni_msgs__msg__OmniState * data =
      (omni_msgs__msg__OmniState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!omni_msgs__msg__OmniState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          omni_msgs__msg__OmniState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!omni_msgs__msg__OmniState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
