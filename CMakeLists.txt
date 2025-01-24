cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)

add_executable(winecraft src/main.cpp)

target_link_libraries(winecraft glfw)