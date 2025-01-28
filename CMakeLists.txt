cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)

add_executable(winecraft 
    src/main.cpp
    src/shader_utils.cpp
)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

file(GLOB_RECURSE SOURCE_SOIL "libs/soil/src/*.c")
add_library(soil ${SOURCE_SOIL})
target_include_directories(soil PUBLIC libs/soil/include)

target_include_directories(winecraft PRIVATE 
    ${CMAKE_SOURCE_DIR}/core
)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(winecraft soil ${OPENGL_LIBRARIES} glad glfw)

target_compile_definitions(winecraft PRIVATE ASSET_PATH="${CMAKE_SOURCE_DIR}/assets/")
