cmake_minimum_required(VERSION 3.10)
project(CPPSTLExamples)

set(CMAKE_CXX_STANDARD 17)


add_executable(csv_example src/csv_example.cpp)
add_executable(unique_values src/unique_values.cpp)
add_executable(city_counter src/city_counter.cpp)
add_executable(sort_custom src/sort_custom.cpp)
