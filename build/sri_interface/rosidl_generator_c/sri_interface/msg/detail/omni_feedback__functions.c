// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sri_interface:msg/OmniFeedback.idl
// generated code does not contain a copyright notice
#include "sri_interface/msg/detail/omni_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `force`
// Member `position`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
sri_interface__msg__OmniFeedback__init(sri_interface__msg__OmniFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__init(&msg->force)) {
    sri_interface__msg__OmniFeedback__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Vector3__init(&msg->position)) {
    sri_interface__msg__OmniFeedback__fini(msg);
    return false;
  }
  return true;
}

void
sri_interface__msg__OmniFeedback__fini(sri_interface__msg__OmniFeedback * msg)
{
  if (!msg) {
    return;
  }
  // force
  geometry_msgs__msg__Vector3__fini(&msg->force);
  // position
  geometry_msgs__msg__Vector3__fini(&msg->position);
}

bool
sri_interface__msg__OmniFeedback__are_equal(const sri_interface__msg__OmniFeedback * lhs, const sri_interface__msg__OmniFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->force), &(rhs->force)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  return true;
}

bool
sri_interface__msg__OmniFeedback__copy(
  const sri_interface__msg__OmniFeedback * input,
  sri_interface__msg__OmniFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // force
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->force), &(output->force)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  return true;
}

sri_interface__msg__OmniFeedback *
sri_interface__msg__OmniFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__OmniFeedback * msg = (sri_interface__msg__OmniFeedback *)allocator.allocate(sizeof(sri_interface__msg__OmniFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sri_interface__msg__OmniFeedback));
  bool success = sri_interface__msg__OmniFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sri_interface__msg__OmniFeedback__destroy(sri_interface__msg__OmniFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sri_interface__msg__OmniFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sri_interface__msg__OmniFeedback__Sequence__init(sri_interface__msg__OmniFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__OmniFeedback * data = NULL;

  if (size) {
    data = (sri_interface__msg__OmniFeedback *)allocator.zero_allocate(size, sizeof(sri_interface__msg__OmniFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sri_interface__msg__OmniFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sri_interface__msg__OmniFeedback__fini(&data[i - 1]);
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
sri_interface__msg__OmniFeedback__Sequence__fini(sri_interface__msg__OmniFeedback__Sequence * array)
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
      sri_interface__msg__OmniFeedback__fini(&array->data[i]);
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

sri_interface__msg__OmniFeedback__Sequence *
sri_interface__msg__OmniFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__OmniFeedback__Sequence * array = (sri_interface__msg__OmniFeedback__Sequence *)allocator.allocate(sizeof(sri_interface__msg__OmniFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sri_interface__msg__OmniFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sri_interface__msg__OmniFeedback__Sequence__destroy(sri_interface__msg__OmniFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sri_interface__msg__OmniFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sri_interface__msg__OmniFeedback__Sequence__are_equal(const sri_interface__msg__OmniFeedback__Sequence * lhs, const sri_interface__msg__OmniFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sri_interface__msg__OmniFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sri_interface__msg__OmniFeedback__Sequence__copy(
  const sri_interface__msg__OmniFeedback__Sequence * input,
  sri_interface__msg__OmniFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sri_interface__msg__OmniFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sri_interface__msg__OmniFeedback * data =
      (sri_interface__msg__OmniFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sri_interface__msg__OmniFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sri_interface__msg__OmniFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sri_interface__msg__OmniFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
