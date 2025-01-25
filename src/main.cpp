#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader_utils.h"
#include <algorithm>
#include <random>
#include <iterator>
#include <thread>
#include <cmath>

using namespace std;



int main() {
    // Иницилизация glfw
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }
    // Создание окна
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    // Добавление окна в контекст что бы оно было видно
    glfwMakeContextCurrent(window);

    // Инициализация glad (загрузка функций OpenGL)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }

    // Координаты трегуольника
    GLfloat vertices[] = {
        //x    // y  // z 
         -0.5f,  -0.5f, 0.5f,
         0.5f, -0.5f, 0.5f,

         0.0f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,
    };

    GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        //1, 0, 3
    };

    //VAO (Vertex Array Object): объект массива вершин. Он хранит конфигурацию, которая описывает, 
    //как интерпретировать данные вершин.
    //VBO (Vertex Buffer Object): буфер данных вершин, который хранится на GPU для быстрого доступа.
    
    GLuint VAO, VBO, EBO, CBO;
        
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &CBO);

    // glBindVertexArray привязывает VAO. Все последующие команды будут записаны в этот VAO.
    // glBindBuffer привязывает VBO как текущий буфер для массива вершин.
    // glBufferData загружает данные вершин в GPU.
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, CBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // glVertexAttribPointer указывает, как читать данные вершин:

    // 0 — номер атрибута (location 0 в шейдере).
    // 3 — количество значений (X, Y, Z).
    // GL_FLOAT — тип данных.
    // GL_FALSE — не нужно нормализовать з#version 330 core
    // 3 * sizeof(GLfloat) — шаг между вершинами (3 float на вершину).
    // (GLvoid*)0 — смещение начала данных.
    // glEnableVertexAttribArray(0)  включает использование атрибута.
    
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, CBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0); 

    // glCreateShader создает объект шейдера.
    // glShaderSource загружает текст шейдера (vertexShaderSource).
    // glCompileShader компилирует шейдер.     


    // Создание программы шейдеров и связывание шейдеров (вершинный + фрагментный)
    GLuint shaderProgram = createShaderProgram("assets/vertex.glsl", "assets/fragment.glsl");

    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Очистка экрана
        glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Добавление шейдеров в программу
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); 


        // Обновляем цвет
        GLfloat timeValue = glfwGetTime();

        GLfloat firstValue = (sin(timeValue) / 2);
        GLfloat secondValue = abs((cos(timeValue) / 2) + 0.5f- 1.0f);
        GLfloat thirdValue = abs((tan(timeValue) / 2) + 0.5f - 1.5f);

        GLint vertexColorLocationGreen = glGetUniformLocation(shaderProgram, "greenColor");
        glUniform3f(vertexColorLocationGreen, thirdValue, firstValue, secondValue);

        GLint vertexColorLocationBlue = glGetUniformLocation(shaderProgram, "blueColor");
        glUniform3f(vertexColorLocationBlue, secondValue, thirdValue, firstValue);

        GLint vertexColorLocationRed = glGetUniformLocation(shaderProgram, "redColor");
        glUniform3f(vertexColorLocationRed, firstValue, secondValue, thirdValue);



        // Рисование треугольника
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
        // Swap buffers and poll events (обработка событий)

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Очистка при заврещении программы
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
