// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from omni_msgs:msg/OmniButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__FUNCTIONS_H_
#define OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "omni_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "omni_msgs/msg/detail/omni_button_event__struct.h"

/// Initialize msg/OmniButtonEvent message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * omni_msgs__msg__OmniButtonEvent
 * )) before or use
 * omni_msgs__msg__OmniButtonEvent__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__init(omni_msgs__msg__OmniButtonEvent * msg);

/// Finalize msg/OmniButtonEvent message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
void
omni_msgs__msg__OmniButtonEvent__fini(omni_msgs__msg__OmniButtonEvent * msg);

/// Create msg/OmniButtonEvent message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * omni_msgs__msg__OmniButtonEvent__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
omni_msgs__msg__OmniButtonEvent *
omni_msgs__msg__OmniButtonEvent__create();

/// Destroy msg/OmniButtonEvent message.
/**
 * It calls
 * omni_msgs__msg__OmniButtonEvent__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
void
omni_msgs__msg__OmniButtonEvent__destroy(omni_msgs__msg__OmniButtonEvent * msg);

/// Check for msg/OmniButtonEvent message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__are_equal(const omni_msgs__msg__OmniButtonEvent * lhs, const omni_msgs__msg__OmniButtonEvent * rhs);

/// Copy a msg/OmniButtonEvent message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__copy(
  const omni_msgs__msg__OmniButtonEvent * input,
  omni_msgs__msg__OmniButtonEvent * output);

/// Initialize array of msg/OmniButtonEvent messages.
/**
 * It allocates the memory for the number of elements and calls
 * omni_msgs__msg__OmniButtonEvent__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__Sequence__init(omni_msgs__msg__OmniButtonEvent__Sequence * array, size_t size);

/// Finalize array of msg/OmniButtonEvent messages.
/**
 * It calls
 * omni_msgs__msg__OmniButtonEvent__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
void
omni_msgs__msg__OmniButtonEvent__Sequence__fini(omni_msgs__msg__OmniButtonEvent__Sequence * array);

/// Create array of msg/OmniButtonEvent messages.
/**
 * It allocates the memory for the array and calls
 * omni_msgs__msg__OmniButtonEvent__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
omni_msgs__msg__OmniButtonEvent__Sequence *
omni_msgs__msg__OmniButtonEvent__Sequence__create(size_t size);

/// Destroy array of msg/OmniButtonEvent messages.
/**
 * It calls
 * omni_msgs__msg__OmniButtonEvent__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
void
omni_msgs__msg__OmniButtonEvent__Sequence__destroy(omni_msgs__msg__OmniButtonEvent__Sequence * array);

/// Check for msg/OmniButtonEvent message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__Sequence__are_equal(const omni_msgs__msg__OmniButtonEvent__Sequence * lhs, const omni_msgs__msg__OmniButtonEvent__Sequence * rhs);

/// Copy an array of msg/OmniButtonEvent messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_omni_msgs
bool
omni_msgs__msg__OmniButtonEvent__Sequence__copy(
  const omni_msgs__msg__OmniButtonEvent__Sequence * input,
  omni_msgs__msg__OmniButtonEvent__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // OMNI_MSGS__MSG__DETAIL__OMNI_BUTTON_EVENT__FUNCTIONS_H_
