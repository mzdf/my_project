cmake_minimum_required(VERSION 3.0)

project(SOLIDERFIRE)


set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAG} -Wall")
###set(CMAKE_BUILD_TYPE Debug)



include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

enable_testing()

add_subdirectory(googletest)


add_executable(my_cmake_exe main.cpp src/Gun.cpp src/Solider.cpp)
add_library(mycode STATIC main.cpp src/Gun.cpp src/Solider.cpp include/Gun.h include/Solider.h)



add_subdirectory(test)
