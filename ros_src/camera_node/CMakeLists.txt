cmake_minimum_required(VERSION 2.8.3)
project(camera_node)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)
add_compile_options(-std=c++11)



## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

include_directories(include)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
)



# catkin_package(
#    INCLUDE_DIRS include
#    CATKIN_DEPENDS roscpp rospy
#    DEPENDS opencv
#    std_msgs 
#    sensor_msgs
# )


catkin_package(
  CATKIN_DEPENDS cv_bridge
  # ...
)

set(CMAKE_PREFIX_PATH /usr/local/share/OpenCV ${CMAKE_PREFIX_PATH})


find_package(OpenCV REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)


add_executable(camera_node src/camera_node.cpp)

target_link_libraries(camera_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)




catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES camera_node
#  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

