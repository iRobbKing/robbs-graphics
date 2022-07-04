cmake_minimum_required(VERSION 3.22)
project(rgraphics)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(deps/glad)
add_subdirectory(deps/glfw)
add_subdirectory(deps/coro)
add_executable(${PROJECT_NAME} main.cpp src/window.cpp src/window.hpp src/buffer.cpp src/buffer.hpp src/vertex_array.cpp src/vertex_array.hpp src/vertex_layout.cpp src/vertex_layout.hpp src/shader.cpp src/shader.hpp src/shader_lib.cpp src/shader_lib.hpp src/material.cpp src/material.hpp)
target_link_libraries(${PROJECT_NAME} glad glfw coro)
