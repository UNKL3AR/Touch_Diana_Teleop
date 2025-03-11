# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_srifts_tcp_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED srifts_tcp_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(srifts_tcp_FOUND FALSE)
  elseif(NOT srifts_tcp_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(srifts_tcp_FOUND FALSE)
  endif()
  return()
endif()
set(_srifts_tcp_CONFIG_INCLUDED TRUE)

# output package information
if(NOT srifts_tcp_FIND_QUIETLY)
  message(STATUS "Found srifts_tcp: 0.0.0 (${srifts_tcp_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'srifts_tcp' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${srifts_tcp_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(srifts_tcp_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${srifts_tcp_DIR}/${_extra}")
endforeach()
