cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 17)

add_executable(HelloWorld src/main.cpp)
add_executable(build_control_flow src/d2/control_flow.cpp)
add_executable(build_input_output src/d2/input_output.cpp)
add_executable(build_day2 src/d2/day2.cpp)
add_executable(build_day2_functions src/d2/functions.cpp)
add_executable(build_day3 src/d3_oob/rectangle_class.cpp)
add_executable(hands_on_class src/d3_oob/hands_on_class.cpp)
add_executable(basic_pointers src/d4_pam/basic_pointers.cpp)
add_executable(dynamic_pointers src/d4_pam/dynamic_memory_management.cpp)
