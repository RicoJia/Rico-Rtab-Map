cmake_minimum_required(VERSION 3.0.2)
project(uda_car_description)


# Note: using catkin REQUIRED COMPENENTS means to add catkin packages
# GAZEBO is not a catkin package, gazebo_ros is!
# However, you still need to find GAZEBO 
find_package(
    catkin REQUIRED COMPONENTS
    gazebo_ros 
)

find_package(
    gazebo REQUIRED
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
    ${GAZEBO_INCLUDE_DIRS}
)

link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

## Declare a C++ library
add_library(hello_plugin SHARED script/hello.cpp)

target_link_libraries(hello_plugin ${GAZEBO_LIBRARIES})
