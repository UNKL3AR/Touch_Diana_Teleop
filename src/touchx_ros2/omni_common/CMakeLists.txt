cmake_minimum_required(VERSION 3.5)
project(omni_common)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(omni_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

set(THIS_PACKAGE_DEPS
  geometry_msgs
  omni_msgs
  sensor_msgs
  std_msgs
  tf2_ros
)
set(THIS_PACKAGE_LIBS
  ${rclcpp_LIBRARIES}
)
set(THIS_PACKAGE_INCLUDE_DIRS
  ${rclcpp_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

find_path(OPENHAPTICS_INCLUDE_DIR NAMES HD/hd.h HL/hl.h HDU/hdu.h)
if(NOT OPENHAPTICS_INCLUDE_DIR)
  set(OPENHAPTICS_MESSAGE "OPENHAPTICS was not found. If you do not have it you will not be able to use the Phantom Omni.")
  message(STATUS "${OPENHAPTICS_MESSAGE}") 
  return()
endif(NOT OPENHAPTICS_INCLUDE_DIR)

add_executable(omni
  src/omni.cpp
)
target_link_libraries(omni
  HD
  HDU
  rt
  ncurses
  ${THIS_PACKAGE_LIBS}
)
target_include_directories(omni
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>  
  ${THIS_PACKAGE_INCLUDE_DIRS}
)
ament_target_dependencies(omni
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${THIS_PACKAGE_DEPS}
)

add_executable(omni_state
  src/omni_state.cpp
)
target_link_libraries(omni_state
  HD
  HDU
  rt
  ncurses
  ${THIS_PACKAGE_LIBS}
)
target_include_directories(omni_state
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>  
  ${THIS_PACKAGE_INCLUDE_DIRS}
)
ament_target_dependencies(omni_state
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${THIS_PACKAGE_DEPS}
)

install(
  TARGETS
    omni
    omni_state
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
