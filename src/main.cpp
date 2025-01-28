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
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        cerr << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cerr << "Failed to initialize GLAD" << endl;
        return -1;
    }

    GLfloat vertices[] = {
         -0.5f,  -0.5f, 0.5f,
         0.5f, -0.5f, 0.5f,
         0.0f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,
    };

    GLfloat colors[] = {
        1.0f, 0.5f, 0.2f,
        0.2f, 1.0f, 0.5f,
        0.5f, 0.2f, 1.0f
    };

    GLuint indices[] = {
        0, 1, 2,
        //1, 0, 3
    };

    GLuint VAO, VBO, EBO, CBO;
        
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &CBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, CBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, CBO);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    glBindVertexArray(0); 

    GLuint shaderProgram = createShaderProgram("assets/vertex.glsl", "assets/fragment.glsl");

    GLint numberPhase = 1; 
    GLfloat previosPhaseValue = 1.0f;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); 

        GLfloat timeValue = (glfwGetTime() + 1.0f);

        GLfloat phaseValue = (ceil(timeValue) - timeValue);
        // cout << timeValue << endl;

        GLint vertexColorLocationPhaseValue = glGetUniformLocation(shaderProgram, "phaseValue");
        glUniform1f(vertexColorLocationPhaseValue, phaseValue);

        if (abs(previosPhaseValue - phaseValue) >= 0.5f){
            numberPhase += 1;
        }
        
        if (numberPhase == 4){
            numberPhase = 1;
        }

        GLint vertexColorLocationNumberPhase = glGetUniformLocation(shaderProgram, "numberPhase");
        glUniform1i(vertexColorLocationNumberPhase, numberPhase);
 
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        previosPhaseValue = phaseValue;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
