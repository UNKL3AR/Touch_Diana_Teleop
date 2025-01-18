cmake_minimum_required(VERSION 3.8)
project(diana_humble)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(DIANA_HUMBLE_INCLUDE ${CMAKE_HOME_DIRECTORY}/include)
set(DIANA_MED_LIB ${CMAKE_HOME_DIRECTORY}/lib)
set(LIB_DIANA_HUMBLE ${DIANA_MED_LIB}/diana_lib/libDianaApi.so)
set(orocos_kdl_LIBRARIES /usr/local/lib/liborocos-kdl.so)
set(DIANA_HUMBLE_SRC src)
set(DIANAMED_CONTROL ${DIANA_HUMBLE_SRC}/dianamed_ctrl.cpp)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(orocos_kdl REQUIRED)
find_package(kdl_parser  REQUIRED)
find_package(urdf  REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(lifecycle_msgs REQUIRED)

include_directories(
  include
  ${DIANA_HUMBLE_INCLUDE}
)

# add_executable(test_med ${DIANA_HUMBLE_SRC}/dianamed_ctrl.cpp)
# target_link_libraries(test_med ${LIB_DIANA_HUMBLE} ${kdl_parser_LIBRARIES} ${orocos_kdl_LIBRARIES})

add_executable(TouchxPose ${DIANA_HUMBLE_SRC}/reset/initTouchxPose.cpp)
target_link_libraries(TouchxPose ${LIB_DIANA_HUMBLE})

add_executable(SquarePath ${DIANA_HUMBLE_SRC}/reset/impedance_c.cpp)
target_link_libraries(SquarePath ${LIB_DIANA_HUMBLE})


add_executable(leave ${DIANA_HUMBLE_SRC}/reset/leave_pos.cpp)
target_link_libraries(leave ${LIB_DIANA_HUMBLE})

add_executable(changeip ${DIANA_HUMBLE_SRC}/reset/change_ip.cpp)
target_link_libraries(changeip ${LIB_DIANA_HUMBLE})

add_executable(state ${DIANA_HUMBLE_SRC}/reset/getstate.cpp)
target_link_libraries(state ${LIB_DIANA_HUMBLE})


add_executable(test_med ${DIANA_HUMBLE_SRC}/test/test.cpp ${DIANAMED_CONTROL})
ament_target_dependencies(test_med rclcpp geometry_msgs  orocos_kdl)
target_link_libraries(test_med ${LIB_DIANA_HUMBLE} ${kdl_parser_LIBRARIES} ${orocos_kdl_LIBRARIES})

add_executable(touchx_lifecycle_node ${DIANA_HUMBLE_SRC}/touchx_lifecycle.cpp ${DIANAMED_CONTROL})
ament_target_dependencies(touchx_lifecycle_node rclcpp geometry_msgs  orocos_kdl rclcpp_lifecycle lifecycle_msgs)
target_link_libraries(touchx_lifecycle_node ${LIB_DIANA_HUMBLE} ${kdl_parser_LIBRARIES} ${orocos_kdl_LIBRARIES})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  test_med
  leave
  SquarePath
  changeip
  state
  TouchxPose
  touchx_lifecycle_node
DESTINATION lib/${PROJECT_NAME})

ament_package()
