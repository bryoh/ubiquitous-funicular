# Library target
add_library(libpng_util STATIC libpng_utils.cpp)

# Include directories for the library
target_include_directories(libpng_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

