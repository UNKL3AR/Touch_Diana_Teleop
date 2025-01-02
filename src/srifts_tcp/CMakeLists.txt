cmake_minimum_required(VERSION 3.8)
project(srifts_tcp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SRIFTS_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include/srifts_tcp)
set(FORCE_SENSOR_SRC src)
set(OMNI_INTERFACE_INCLUDE /home/pc/zyh/ultrasound/Diana_omni_ws/install/omni_msgs/include/omni_msgs)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(omni_msgs REQUIRED)

include_directories(
  include
  ${SRIFTS_INCLUDE}
  ${OMNI_INTERFACE_INCLUDE}
)

add_executable(fts ${FORCE_SENSOR_SRC}/srifts_tcp.cpp ${FORCE_SENSOR_SRC}/TCP_sock.cpp)
ament_target_dependencies(fts rclcpp geometry_msgs std_msgs)

add_executable(ttt ${FORCE_SENSOR_SRC}/srifts_tcpcopy.cpp ${FORCE_SENSOR_SRC}/TCP_sock.cpp)
ament_target_dependencies(ttt rclcpp geometry_msgs std_msgs)

add_executable(fd ${FORCE_SENSOR_SRC}/feedback.cpp)
ament_target_dependencies(fd rclcpp geometry_msgs omni_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  fts
  ttt
  fd
DESTINATION lib/${PROJECT_NAME})

ament_package()
