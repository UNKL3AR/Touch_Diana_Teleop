// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from sri_interface:msg/SixAxisFTS.idl
// generated code does not contain a copyright notice

#ifndef SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__FUNCTIONS_H_
#define SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "sri_interface/msg/rosidl_generator_c__visibility_control.h"

#include "sri_interface/msg/detail/six_axis_fts__struct.h"

/// Initialize msg/SixAxisFTS message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * sri_interface__msg__SixAxisFTS
 * )) before or use
 * sri_interface__msg__SixAxisFTS__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__init(sri_interface__msg__SixAxisFTS * msg);

/// Finalize msg/SixAxisFTS message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
void
sri_interface__msg__SixAxisFTS__fini(sri_interface__msg__SixAxisFTS * msg);

/// Create msg/SixAxisFTS message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * sri_interface__msg__SixAxisFTS__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
sri_interface__msg__SixAxisFTS *
sri_interface__msg__SixAxisFTS__create();

/// Destroy msg/SixAxisFTS message.
/**
 * It calls
 * sri_interface__msg__SixAxisFTS__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
void
sri_interface__msg__SixAxisFTS__destroy(sri_interface__msg__SixAxisFTS * msg);

/// Check for msg/SixAxisFTS message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__are_equal(const sri_interface__msg__SixAxisFTS * lhs, const sri_interface__msg__SixAxisFTS * rhs);

/// Copy a msg/SixAxisFTS message.
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
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__copy(
  const sri_interface__msg__SixAxisFTS * input,
  sri_interface__msg__SixAxisFTS * output);

/// Initialize array of msg/SixAxisFTS messages.
/**
 * It allocates the memory for the number of elements and calls
 * sri_interface__msg__SixAxisFTS__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__Sequence__init(sri_interface__msg__SixAxisFTS__Sequence * array, size_t size);

/// Finalize array of msg/SixAxisFTS messages.
/**
 * It calls
 * sri_interface__msg__SixAxisFTS__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
void
sri_interface__msg__SixAxisFTS__Sequence__fini(sri_interface__msg__SixAxisFTS__Sequence * array);

/// Create array of msg/SixAxisFTS messages.
/**
 * It allocates the memory for the array and calls
 * sri_interface__msg__SixAxisFTS__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
sri_interface__msg__SixAxisFTS__Sequence *
sri_interface__msg__SixAxisFTS__Sequence__create(size_t size);

/// Destroy array of msg/SixAxisFTS messages.
/**
 * It calls
 * sri_interface__msg__SixAxisFTS__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
void
sri_interface__msg__SixAxisFTS__Sequence__destroy(sri_interface__msg__SixAxisFTS__Sequence * array);

/// Check for msg/SixAxisFTS message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__Sequence__are_equal(const sri_interface__msg__SixAxisFTS__Sequence * lhs, const sri_interface__msg__SixAxisFTS__Sequence * rhs);

/// Copy an array of msg/SixAxisFTS messages.
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
ROSIDL_GENERATOR_C_PUBLIC_sri_interface
bool
sri_interface__msg__SixAxisFTS__Sequence__copy(
  const sri_interface__msg__SixAxisFTS__Sequence * input,
  sri_interface__msg__SixAxisFTS__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SRI_INTERFACE__MSG__DETAIL__SIX_AXIS_FTS__FUNCTIONS_H_
