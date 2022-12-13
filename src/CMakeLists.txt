cmake_minimum_required(VERSION 3.0.2)
project(main_node)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  message_generation
  std_msgs
  geometry_msgs

)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS 
  message_runtime 
  roscpp 
  rosgraph_msgs 
  rospy 
  std_msgs
  geometry_msgs
)


include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(main src/nodes/main_node.cpp src/main.cpp)
target_link_libraries(main ${catkin_LIBRARIES})


# include_directories(include ${catkin_INCLUDE_DIRS})
# add_executable(sub_node src/nodes/sub_node.cpp src/sub_node.cpp)
# target_link_libraries(main ${catkin_LIBRARIES})

# include_directories(include ${catkin_INCLUDE_DIRS})
# add_executable(pub_node src/nodes/pub_node.cpp src/pub_node.cpp)
# target_link_libraries(main ${catkin_LIBRARIES})





catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES main_node
#  CATKIN_DEPENDS roscpp
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

