cmake_minimum_required(VERSION 3.15)
project(kusoma_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Core exercises
add_executable(HelloWorld src/main.cpp)
add_executable(build_control_flow src/d2/control_flow.cpp)
add_executable(build_input_output src/d2/input_output.cpp)
add_executable(build_day2 src/d2/day2.cpp)
add_executable(build_day2_functions src/d2/functions.cpp)
add_executable(build_day3 src/d3_oob/rectangle_class.cpp)
add_executable(hands_on_class src/d3_oob/hands_on_class.cpp)
add_executable(basic_pointers src/d4_pam/basic_pointers.cpp)
add_executable(dynamic_pointers src/d4_pam/dynamic_memory_management.cpp)

# STL day 8 samples
add_executable(csv_example src/cpp-stl-day8/src/csv_example.cpp)
add_executable(unique_values src/cpp-stl-day8/src/unique_values.cpp)
add_executable(city_counter src/cpp-stl-day8/src/city_counter.cpp)
add_executable(sort_custom src/cpp-stl-day8/src/sort_custom.cpp)

# libpng example (optional if libpng is present)
find_package(PNG QUIET)
if(PNG_FOUND)
  add_library(libpng_utils STATIC
    libpng_example/lib/libpng_utils.cpp
  )
  target_include_directories(libpng_utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libpng_example/lib
  )
  target_link_libraries(libpng_utils PUBLIC PNG::PNG)

  add_executable(libpng_example
    libpng_example/src/main.cpp
  )
  target_include_directories(libpng_example PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/libpng_example/lib
  )
  target_link_libraries(libpng_example PRIVATE libpng_utils)
else()
  message(WARNING "libpng not found; libpng_example target will not be built.")
endif()

# Qt Widgets example (optional if Qt5 is present)
find_package(Qt5 COMPONENTS Widgets QUIET)
if(Qt5Widgets_FOUND)
  add_executable(Day7QtApp
    src/d7qt1/Day7QtApp/main.cpp
    src/d7qt1/Day7QtApp/mainwindow.cpp
    src/d7qt1/Day7QtApp/mainwindow.h
    src/d7qt1/Day7QtApp/mainwindow.ui
  )
  set_target_properties(Day7QtApp PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
  )
  target_link_libraries(Day7QtApp PRIVATE Qt5::Widgets)
else()
  message(WARNING "Qt5 Widgets not found; Day7QtApp target will not be built.")
endif()
