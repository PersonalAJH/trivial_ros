cmake_minimum_required(VERSION 3.0.2)
project(pub_node)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
)


catkin_package(
 INCLUDE_DIRS include
 LIBRARIES pub_node
 CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs
 DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(pub_node src/publish_node.cpp)
target_link_libraries(pub_node ${catkin_LIBRARIES})

