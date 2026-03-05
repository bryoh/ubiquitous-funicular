# Executable target 

add_executable(libpng_example main.cpp)

# Link with libpng_utils
target_link_libraries(libpng_example PRIVATE libpng_utils PNG::PNG)
