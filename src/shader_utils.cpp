#include "shader_utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Функция для загрузки текста шейдера из файла
// filePath — путь к файлу с шейдером
std::string loadShaderSource(const char* filePath) {
    std::ifstream file(filePath); // Открываем файл
    std::stringstream buffer;

    if (file.is_open()) {
        buffer << file.rdbuf(); // Читаем содержимое файла в строку
        file.close();           // Закрываем файл
    } else {
        std::cerr << "Не удалось открыть файл шейдера: " << filePath << std::endl;
    }

    return buffer.str(); // Возвращаем содержимое файла
}

// Функция для создания и компиляции шейдера
// filePath — путь к файлу с кодом шейдера
// shaderType — тип шейдера (GL_VERTEX_SHADER или GL_FRAGMENT_SHADER)
GLuint createShader(const char* filePath, GLenum shaderType) {
    // Загружаем текст шейдера из файла
    std::string shaderCode = loadShaderSource(filePath);
    const char* shaderSource = shaderCode.c_str(); // Преобразуем строку в C-строку

    // Создаем объект шейдера
    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &shaderSource, nullptr); // Передаем код шейдера
    glCompileShader(shader); // Компилируем шейдер

    // Проверяем успешность компиляции
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog); // Считываем сообщение об ошибке
        std::cerr << "Ошибка компиляции шейдера: " << filePath << "\n" << infoLog << std::endl;
    }

    return shader; // Возвращаем ID шейдера
}

// Функция для создания программы шейдеров
// vertexPath — путь к файлу с вершинным шейдером
// fragmentPath — путь к файлу с фрагментным шейдером
GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath) {
    // Создаем и компилируем вершинный и фрагментный шейдеры
    GLuint vertexShader = createShader(vertexPath, GL_VERTEX_SHADER);
    GLuint fragmentShader = createShader(fragmentPath, GL_FRAGMENT_SHADER);

    // Создаем объект программы и привязываем к ней шейдеры
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program); // Линкуем шейдерную программу

    // Проверяем успешность линковки
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, nullptr, infoLog); // Считываем сообщение об ошибке
        std::cerr << "Ошибка линковки программы шейдеров\n" << infoLog << std::endl;
    }

    // Удаляем объекты шейдеров, так как они уже привязаны к программе
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program; // Возвращаем ID программы
}
