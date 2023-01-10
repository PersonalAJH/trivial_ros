cmake_minimum_required(VERSION 3.0.2)
project(sub_node)




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

find_package(catkin REQUIRED COMPONENTS roslaunch)
roslaunch_add_file_check(launch)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES pub_node
 CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs
 DEPENDS system_lib
)

# include_directories(
#   ${catkin_INCLUDE_DIRS}
# )


# include_directories(include ${catkin_INCLUDE_DIRS})
# add_executable(sub_node src/sub_node/listener_node.cpp src/sub_node/listener_node.cpp)
# target_link_libraries(sub_node ${catkin_LIBRARIES})
