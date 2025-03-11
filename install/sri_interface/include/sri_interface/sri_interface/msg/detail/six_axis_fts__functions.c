// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice
#include "sri_interface/msg/detail/six_axis_fts__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
sri_interface__msg__SixAxisFTS__init(sri_interface__msg__SixAxisFTS * msg)
{
  if (!msg) {
    return false;
  }
  // x_force
  // y_force
  // z_force
  // x_torque
  // y_torque
  // z_torque
  // frame_number
  // sampling_time
  return true;
}

void
sri_interface__msg__SixAxisFTS__fini(sri_interface__msg__SixAxisFTS * msg)
{
  if (!msg) {
    return;
  }
  // x_force
  // y_force
  // z_force
  // x_torque
  // y_torque
  // z_torque
  // frame_number
  // sampling_time
}

bool
sri_interface__msg__SixAxisFTS__are_equal(const sri_interface__msg__SixAxisFTS * lhs, const sri_interface__msg__SixAxisFTS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_force
  if (lhs->x_force != rhs->x_force) {
    return false;
  }
  // y_force
  if (lhs->y_force != rhs->y_force) {
    return false;
  }
  // z_force
  if (lhs->z_force != rhs->z_force) {
    return false;
  }
  // x_torque
  if (lhs->x_torque != rhs->x_torque) {
    return false;
  }
  // y_torque
  if (lhs->y_torque != rhs->y_torque) {
    return false;
  }
  // z_torque
  if (lhs->z_torque != rhs->z_torque) {
    return false;
  }
  // frame_number
  if (lhs->frame_number != rhs->frame_number) {
    return false;
  }
  // sampling_time
  if (lhs->sampling_time != rhs->sampling_time) {
    return false;
  }
  return true;
}

bool
sri_interface__msg__SixAxisFTS__copy(
  const sri_interface__msg__SixAxisFTS * input,
  sri_interface__msg__SixAxisFTS * output)
{
  if (!input || !output) {
    return false;
  }
  // x_force
  output->x_force = input->x_force;
  // y_force
  output->y_force = input->y_force;
  // z_force
  output->z_force = input->z_force;
  // x_torque
  output->x_torque = input->x_torque;
  // y_torque
  output->y_torque = input->y_torque;
  // z_torque
  output->z_torque = input->z_torque;
  // frame_number
  output->frame_number = input->frame_number;
  // sampling_time
  output->sampling_time = input->sampling_time;
  return true;
}

sri_interface__msg__SixAxisFTS *
sri_interface__msg__SixAxisFTS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__SixAxisFTS * msg = (sri_interface__msg__SixAxisFTS *)allocator.allocate(sizeof(sri_interface__msg__SixAxisFTS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(sri_interface__msg__SixAxisFTS));
  bool success = sri_interface__msg__SixAxisFTS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
sri_interface__msg__SixAxisFTS__destroy(sri_interface__msg__SixAxisFTS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    sri_interface__msg__SixAxisFTS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
sri_interface__msg__SixAxisFTS__Sequence__init(sri_interface__msg__SixAxisFTS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__SixAxisFTS * data = NULL;

  if (size) {
    data = (sri_interface__msg__SixAxisFTS *)allocator.zero_allocate(size, sizeof(sri_interface__msg__SixAxisFTS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = sri_interface__msg__SixAxisFTS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        sri_interface__msg__SixAxisFTS__fini(&data[i - 1]);
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
sri_interface__msg__SixAxisFTS__Sequence__fini(sri_interface__msg__SixAxisFTS__Sequence * array)
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
      sri_interface__msg__SixAxisFTS__fini(&array->data[i]);
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

sri_interface__msg__SixAxisFTS__Sequence *
sri_interface__msg__SixAxisFTS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  sri_interface__msg__SixAxisFTS__Sequence * array = (sri_interface__msg__SixAxisFTS__Sequence *)allocator.allocate(sizeof(sri_interface__msg__SixAxisFTS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = sri_interface__msg__SixAxisFTS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
sri_interface__msg__SixAxisFTS__Sequence__destroy(sri_interface__msg__SixAxisFTS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    sri_interface__msg__SixAxisFTS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
sri_interface__msg__SixAxisFTS__Sequence__are_equal(const sri_interface__msg__SixAxisFTS__Sequence * lhs, const sri_interface__msg__SixAxisFTS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!sri_interface__msg__SixAxisFTS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
sri_interface__msg__SixAxisFTS__Sequence__copy(
  const sri_interface__msg__SixAxisFTS__Sequence * input,
  sri_interface__msg__SixAxisFTS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(sri_interface__msg__SixAxisFTS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    sri_interface__msg__SixAxisFTS * data =
      (sri_interface__msg__SixAxisFTS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!sri_interface__msg__SixAxisFTS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          sri_interface__msg__SixAxisFTS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!sri_interface__msg__SixAxisFTS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
