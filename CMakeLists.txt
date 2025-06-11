cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)

add_executable(winecraft
    src/main.cpp
    src/utils/texture_loader.cpp
    src/utils/shader_utils.cpp
    src/utils/assets.cpp
    src/utils/createEntities.cpp
    src/classes/entities/entity.cpp
    src/classes/objects/Object.cpp
    src/classes/worldKeeper/worldKeeper.cpp
    src/classes/extensions/extension.cpp
    src/classes/extensions/positionExtension.cpp
    src/classes/extensions/moveMentExtension.cpp
    src/classes/extensions/objectExtension.cpp
    src/classes/worldKeeper/keyTrigger.cpp
    src/classes/objects/Cube.cpp
    src/classes/extensions/collisionExtension/collisionExtension.cpp
    src/classes/hitBox/hitBoxRect.cpp
    src/classes/hitBox/hitBox.cpp
    src/classes/extensions/physicsExtension.cpp
)

include(FetchContent)
FetchContent_Declare(soil2  
    GIT_REPOSITORY https://github.com/SpartanJ/SOIL2  
    GIT_TAG master  
)  
FetchContent_MakeAvailable(soil2)

add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

target_include_directories(winecraft PRIVATE
    ${CMAKE_SOURCE_DIR}/core
)

target_include_directories(winecraft PRIVATE
    ${CMAKE_SOURCE_DIR}/core/entities
)

target_include_directories(winecraft PRIVATE  
    ${soil2_SOURCE_DIR}/src  
)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

target_link_libraries(winecraft PRIVATE soil2 glad glfw OpenGL::GL glm::glm)

target_compile_definitions(winecraft PRIVATE ASSET_PATH="${CMAKE_SOURCE_DIR}/assets/")
