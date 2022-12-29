cmake_minimum_required(VERSION 3.0.2)
project(camera_node)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED)


## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs message_generation)

catkin_package(
   INCLUDE_DIRS include
   CATKIN_DEPENDS roscpp rospy
   DEPENDS opencv
   std_msgs 
   sensor_msgs
)

## Declare ROS messages and services
# add_message_files(FILES Num.msg)
# add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
# sensor_msg is not used in this code maybe......
generate_messages(DEPENDENCIES std_msgs sensor_msgs)


## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(camera_node src/camera_node.cpp)
target_link_libraries(camera_node ${catkin_LIBRARIES})

add_executable(camera_node src/camera_pynode.py)
target_link_libraries(camera_node ${catkin_LIBRARIES})


