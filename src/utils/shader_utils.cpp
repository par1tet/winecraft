#include "shader_utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string loadShaderSource(const char* filePath) {
    std::ifstream file(filePath);
    std::stringstream buffer;


    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл шейдера: " << filePath << std::endl;
    }

    return buffer.str();
}

GLuint createShader(const char* filePath, GLenum shaderType) {
    std::string shaderCode = loadShaderSource(filePath);
    const char* shaderSource = shaderCode.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Ошибка компиляции шейдера: " << filePath << "\n" << infoLog << std::endl;
    }

    return shader;
}

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    GLuint vertexShader = createShader(vertexPath, GL_VERTEX_SHADER);
    GLuint fragmentShader = createShader(fragmentPath, GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        std::cerr << "Ошибка линковки программы шейдеров\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}
