cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)

add_executable(winecraft
    src/main.cpp
    src/utils/shader_utils.cpp
    src/utils/texture_loader.cpp
    src/graphics/collisions.cpp
    src/utils/assets.cpp
    src/control/movement.cpp
)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

file(GLOB_RECURSE SOURCE_SOIL "libs/soil/src/*.c")
add_library(soil STATIC ${SOURCE_SOIL})
target_include_directories(soil PUBLIC libs/soil/include)

target_include_directories(winecraft PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)

target_include_directories(winecraft PRIVATE
    ${CMAKE_SOURCE_DIR}/core/entities
)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(winecraft PRIVATE soil glad glfw OpenGL::GL glm::glm)

target_compile_definitions(winecraft PRIVATE ASSET_PATH="${CMAKE_SOURCE_DIR}/assets/")
