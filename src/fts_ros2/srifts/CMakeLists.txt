cmake_minimum_required(VERSION 3.8)
project(srifts)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SRIFTS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include/srifts)
set(SRI_INTERFACE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/install/sri_interface/include/sri_interface)
set(OMNI_INTERFACE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/install/omni_msgs/include/omni_msgs)
set(FORCE_SENSOR_SRC src)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sri_interface REQUIRED)
find_package(omni_msgs REQUIRED)
find_package(serial REQUIRED)

include_directories(
  include
  ${SRIFTS_INCLUDE}
  ${SRI_INTERFACE_INCLUDE}
  ${OMNI_INTERFACE_INCLUDE}
)

add_executable(forcesensor ${FORCE_SENSOR_SRC}/M8128_data.cpp)
ament_target_dependencies(forcesensor rclcpp geometry_msgs serial sri_interface)

add_executable(kalman ${FORCE_SENSOR_SRC}/kalman.cpp)
ament_target_dependencies(kalman rclcpp geometry_msgs omni_msgs  sri_interface)

 
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  forcesensor
  # forcefeedback
  kalman
  # kalman_mean
DESTINATION lib/${PROJECT_NAME})

ament_package()
