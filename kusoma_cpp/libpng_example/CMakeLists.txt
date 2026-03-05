cmake_minimum_required(VERSION 3.15)
project(libpng_example)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(lib)
add_subdirectory(src)

# Add exectuable
# add_executable(libpng_example src/main.cpp) 

#Find libpng
# find_package(PNG REQUIRED)
#
# # Link libpng to the executable
# target_link_libraries(libpng_example PRIVATE PNG::PNG)
#
#
# if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
#   message(FATAL_ERROR "Source file src/main.cpp not found.")
# endif()
#
# if (PNG_FOUND)
#   message(STAUTS "libpng found")
# else()
#   message(FATAL_ERROR "libpng not found")
# endif()
#
# # Install rules
# install(TARGETS libpng_example DESTINATION bin)

