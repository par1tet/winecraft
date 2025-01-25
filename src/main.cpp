#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader_utils.h"
#include <thread>


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
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         -0.5f, 0.5f, 0.0f,
    };

    GLuint indices[] = {
        2, 1, 3,
        1, 0, 3
    };

    //VAO (Vertex Array Object): объект массива вершин. Он хранит конфигурацию, которая описывает, 
    //как интерпретировать данные вершин.
    //VBO (Vertex Buffer Object): буфер данных вершин, который хранится на GPU для быстрого доступа.
    
    GLuint VAO, VBO, EBO;
        
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // glBindVertexArray привязывает VAO. Все последующие команды будут записаны в этот VAO.
    // glBindBuffer привязывает VBO как текущий буфер для массива вершин.
    // glBufferData загружает данные вершин в GPU.
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // glVertexAttribPointer указывает, как читать данные вершин:

    // 0 — номер атрибута (location 0 в шейдере).
    // 3 — количество значений (X, Y, Z).
    // GL_FLOAT — тип данных.
    // GL_FALSE — не нужно нормализовать значения.
    // 3 * sizeof(GLfloat) — шаг между вершинами (3 float на вершину).
    // (GLvoid*)0 — смещение начала данных.
    // glEnableVertexAttribArray(0)  включает использование атрибута.
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0); 

    // glCreateShader создает объект шейдера.
    // glShaderSource загружает текст шейдера (vertexShaderSource).
    // glCompileShader компилирует шейдер.     


    // Создание программы шейдеров и связывание шейдеров (вершинный + фрагментный)
    GLuint shaderProgram = createShaderProgram("assets/vertex.glsl", "assets/fragment.glsl");

    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Очистка экрана
        glClear(GL_COLOR_BUFFER_BIT);

        // Добавление шейдеров в программу
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); 

        // Рисование треугольника
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
