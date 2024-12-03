cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloWorld src/main.cpp)
add_executable(build_control_flow src/d2/control_flow.cpp)
add_executable(build_input_output src/d2/input_output.cpp)
add_executable(build_day2 src/d2/day2.cpp)
add_executable(build_day2_functions src/d2/functions.cpp)
