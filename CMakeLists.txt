cmake_minimum_required(VERSION 3.18)
project(winecraft VERSION 0.1.0)


# Главный исполняемый файл
add_executable(winecraft 
    src/main.cpp
    src/shader_utils.cpp
)

# Добавляем библиотеку GLAD
add_library(glad STATIC libs/glad/src/glad.c)
target_include_directories(glad PUBLIC libs/glad/include)

# Указываем путь к заголовочным файлам
target_include_directories(winecraft PRIVATE 
    ${CMAKE_SOURCE_DIR}/core  # Путь к core
)

# Подключаем библиотеку GLFW
find_package(glfw3 REQUIRED)
target_link_libraries(winecraft glad glfw)

# Указываем путь для ресурсов (шэйдеров)
target_compile_definitions(winecraft PRIVATE ASSET_PATH="${CMAKE_SOURCE_DIR}/assets/")
