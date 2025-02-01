#include "glad/glad.h"
#include "shader_utils.h"
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vars.h>
#include <collisions.h>
#include "assets.h"
#include "controls.hpp"

using namespace std;

const float moveXY = 0.1f;

void handleMoves(const std::vector<AABB>& objects) {
	if(!checkCollisions(objects)){
		if (PressedW) {
			cubePositions[0][1] += moveXY;
		}
		if (PressedS) {
			cubePositions[0][1] -= moveXY;
		}
		if (PressedA) {
			cubePositions[0][0] -= moveXY;
		}
		if (PressedD) {
			cubePositions[0][0] += moveXY;
		}
	}

	if(!checkCollisions(objects)){
		if (PressedUp) {
			cubePositions[1][1] += moveXY;
		}
		if (PressedDown) {
			cubePositions[1][1] -= moveXY;
		}
		if (PressedLeft) {
			cubePositions[1][0] -= moveXY;
		}
		if (PressedRight) {
			cubePositions[1][0] += moveXY;
		}
	}
}

int main() {
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
  	}

	GLFWwindow *window = glfwCreateWindow(width, height, "Winecraft 0.1", nullptr, nullptr);

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

    glViewport(0, 0, width, height);

    glfwSetKeyCallback(window, key_callback);

    GLuint shaderProgram = createShaderProgram(
      	getAssetPath("shaders/vertex.glsl").c_str(),
      	getAssetPath("shaders/fragment.glsl").c_str()
    );

    GLuint VAO, VBO, EBO, TBO;

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &TBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, TBO);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
    glEnableVertexAttribArray(1);
    // load texture
    GLuint texture = loadTexture(getAssetPath("textures/murych_cat.png").c_str());

    GLdouble previosTimeDelay = 0.0f, previosTime = 0.0f, delayTime = moveXY/targetFps;
    int fps;

    glEnable(GL_DEPTH_TEST);

    // Main loop : λι τνκ υζσλκ
    while (!glfwWindowShouldClose(window)) {
      	glfwPollEvents();

      	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      	GLdouble time = glfwGetTime();

        vector<AABB> positions;

      	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
      	glClear(GL_COLOR_BUFFER_BIT);

      	glUseProgram(shaderProgram);

      	glm::mat4 viewMatrix = glm::mat4(1.0f);
      	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -20.0f));

      	glm::mat4 projectionMatrix = glm::mat4(1.0f);
      	projectionMatrix = glm::perspective(glm::radians(45.0f), float(width/height), 0.1f, 100.0f);

      	GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
      	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
      	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
      	GLuint transLocation = glGetUniformLocation(shaderProgram, "transform");
      	GLuint colorLocation = glGetUniformLocation(shaderProgram, "colorCube");
      	GLuint sizeLocation = glGetUniformLocation(shaderProgram, "sizeCube");

      	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
      	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

      	glUseProgram(shaderProgram);
      	glBindTexture(GL_TEXTURE_2D, texture);

      	glBindVertexArray(VAO);

        for(int i = 0;i < sizeof(cubePositions)/sizeof(cubePositions[0]); i++){
      		glm::mat4 modelMatrix = glm::mat4(1.0f);
        	modelMatrix = glm::translate(modelMatrix, cubePositions[i]);
          
      		glm::mat4 trans = glm::mat4(1.0f);
      		trans = glm::translate(trans, glm::vec3(cubePositions[i][0], cubePositions[i][1], 0.0f));
          positions.push_back(calculateAABB(cubePositions[i], cubeSizes[i]));
        float color[] = {(float)i, 1.0f, 1.0f, 1.0f};

      		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
      		glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(trans));
          glUniform4fv(colorLocation, 1, color);
          glUniform1f(sizeLocation, cubeSizes[i]);

      		glDrawArrays(GL_TRIANGLES, 0, 36);
		}
      
      	if(time - previosTimeDelay >= delayTime){
      		handleMoves(positions);
      		previosTimeDelay = time;
      	}

        fps = 1 / (time-previosTime);
      	glBindVertexArray(0);
      	glfwSwapBuffers(window);
      	previosTime = time;
    positions.clear();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
