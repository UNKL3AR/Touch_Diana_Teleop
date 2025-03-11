// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice
#include "omni_msgs/msg/detail/omni_button_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
omni_msgs__msg__OmniButtonEvent__init(omni_msgs__msg__OmniButtonEvent * msg)
{
  if (!msg) {
    return false;
  }
  // grey_button
  // white_button
  return true;
}

void
omni_msgs__msg__OmniButtonEvent__fini(omni_msgs__msg__OmniButtonEvent * msg)
{
  if (!msg) {
    return;
  }
  // grey_button
  // white_button
}

bool
omni_msgs__msg__OmniButtonEvent__are_equal(const omni_msgs__msg__OmniButtonEvent * lhs, const omni_msgs__msg__OmniButtonEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // grey_button
  if (lhs->grey_button != rhs->grey_button) {
    return false;
  }
  // white_button
  if (lhs->white_button != rhs->white_button) {
    return false;
  }
  return true;
}

bool
omni_msgs__msg__OmniButtonEvent__copy(
  const omni_msgs__msg__OmniButtonEvent * input,
  omni_msgs__msg__OmniButtonEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // grey_button
  output->grey_button = input->grey_button;
  // white_button
  output->white_button = input->white_button;
  return true;
}

omni_msgs__msg__OmniButtonEvent *
omni_msgs__msg__OmniButtonEvent__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniButtonEvent * msg = (omni_msgs__msg__OmniButtonEvent *)allocator.allocate(sizeof(omni_msgs__msg__OmniButtonEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(omni_msgs__msg__OmniButtonEvent));
  bool success = omni_msgs__msg__OmniButtonEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
omni_msgs__msg__OmniButtonEvent__destroy(omni_msgs__msg__OmniButtonEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    omni_msgs__msg__OmniButtonEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
omni_msgs__msg__OmniButtonEvent__Sequence__init(omni_msgs__msg__OmniButtonEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniButtonEvent * data = NULL;

  if (size) {
    data = (omni_msgs__msg__OmniButtonEvent *)allocator.zero_allocate(size, sizeof(omni_msgs__msg__OmniButtonEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = omni_msgs__msg__OmniButtonEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        omni_msgs__msg__OmniButtonEvent__fini(&data[i - 1]);
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
omni_msgs__msg__OmniButtonEvent__Sequence__fini(omni_msgs__msg__OmniButtonEvent__Sequence * array)
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
      omni_msgs__msg__OmniButtonEvent__fini(&array->data[i]);
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

omni_msgs__msg__OmniButtonEvent__Sequence *
omni_msgs__msg__OmniButtonEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  omni_msgs__msg__OmniButtonEvent__Sequence * array = (omni_msgs__msg__OmniButtonEvent__Sequence *)allocator.allocate(sizeof(omni_msgs__msg__OmniButtonEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = omni_msgs__msg__OmniButtonEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
omni_msgs__msg__OmniButtonEvent__Sequence__destroy(omni_msgs__msg__OmniButtonEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    omni_msgs__msg__OmniButtonEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
omni_msgs__msg__OmniButtonEvent__Sequence__are_equal(const omni_msgs__msg__OmniButtonEvent__Sequence * lhs, const omni_msgs__msg__OmniButtonEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!omni_msgs__msg__OmniButtonEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
omni_msgs__msg__OmniButtonEvent__Sequence__copy(
  const omni_msgs__msg__OmniButtonEvent__Sequence * input,
  omni_msgs__msg__OmniButtonEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(omni_msgs__msg__OmniButtonEvent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    omni_msgs__msg__OmniButtonEvent * data =
      (omni_msgs__msg__OmniButtonEvent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!omni_msgs__msg__OmniButtonEvent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          omni_msgs__msg__OmniButtonEvent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!omni_msgs__msg__OmniButtonEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
