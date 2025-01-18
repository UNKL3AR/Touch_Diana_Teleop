cmake_minimum_required(VERSION 3.8)
project(master_slave_map)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(orocos_kdl REQUIRED)
find_package(ament_lint_auto REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(ament_index_cpp REQUIRED)

add_executable(omni_diana_pose src/omni_diana_pose.cpp)
ament_target_dependencies(omni_diana_pose
  rclcpp
  orocos_kdl
  geometry_msgs
  std_msgs
  builtin_interfaces
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  omni_diana_pose
  DESTINATION lib/${PROJECT_NAME})

ament_package()
