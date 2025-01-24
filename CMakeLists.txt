cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)


add_executable(winecraft src/main.cpp)

add_library(glad STATIC libs/glad/include/glad/glad.h libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

find_package(glfw3 REQUIRED)
target_link_libraries(winecraft glad glfw)
