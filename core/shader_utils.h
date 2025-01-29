#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H

#include <string>
#include <glad/glad.h>

// Загрузка исходного кода шейдера из файла
std::string loadShaderSource(const char* filePath);

// Создание и компиляция шейдера (вершинного или фрагментного)
GLuint createShader(const char* filePath, GLenum shaderType);

// Создание программы шейдеров (объединяет вершинный и фрагментный шейдеры)
GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath);

GLuint loadTexture(const char* filePath);

#endif
