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

using namespace std;

float x = 0, y = 0;

bool PressedW = false;
bool PressedS = false;
bool PressedA = false;
bool PressedD = false;

const float moveXY = 0.04f;

void handleMoves() {
  	if (PressedW) {
		y += moveXY;
  	}
  	if (PressedS) {
		y -= moveXY;
  	}
  	if (PressedA) {
		x -= moveXY;
  	}
  	if (PressedD) {
		x += moveXY;
  	}
}

std::string getAssetPath(const std::string &relativePath) {
  	return std::string(ASSET_PATH) + relativePath;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
  	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
	  		PressedW = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedW = false;
		}
  	}

  	if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
	  		PressedS = true;
	} else if (action == GLFW_RELEASE) {
	  		PressedS = false;
		}
  	}

  	if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
	  		PressedA = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedA = false;
		}
  	}
  
  	if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) {
	  		PressedD = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedD = false;
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
    GLdouble fps;

    glEnable(GL_DEPTH_TEST);

    // Main loop : λι τνκ υζσλκ 
    while (!glfwWindowShouldClose(window)) {
      	glfwPollEvents();

      	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      	GLdouble time = glfwGetTime();

      	if(time - previosTimeDelay >= delayTime){
      		handleMoves();
      		previosTimeDelay = time;
      	}

      	fps = 1 / (time-previosTime);
      
      	system("clear");
      	cout << fps << endl;

      	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
      	glClear(GL_COLOR_BUFFER_BIT);

      	glm::mat4 trans = glm::mat4(1.0f);
      	trans = glm::translate(trans, glm::vec3(x, y, 0.0f));
      	glUseProgram(shaderProgram);

      	glm::mat4 modelMatrix = glm::mat4(1.0f);
      	glm::mat4 viewMatrix = glm::mat4(1.0f);
      	glm::mat4 projectionMatrix = glm::mat4(1.0f);
		
      	modelMatrix = glm::rotate(modelMatrix, glm::radians(-50.0f), glm::vec3(1.0f, 0.0f, 0.0f));
      	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -3.0f));
      	projectionMatrix = glm::perspective(glm::radians(45.0f), float(width/height), 0.1f, 100.0f);

      	GLuint modelMatixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
      	GLuint viewMatixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
      	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
      	GLuint transLocation = glGetUniformLocation(shaderProgram, "transform");

      	glUniformMatrix4fv(modelMatixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
      	glUniformMatrix4fv(viewMatixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
      	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
      	glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(trans));

      	glUseProgram(shaderProgram);
      	glBindTexture(GL_TEXTURE_2D, texture);
      	glBindVertexArray(VAO);
      	glDrawArrays(GL_TRIANGLES, 0, 36);

      	glBindVertexArray(0);
      	glfwSwapBuffers(window);
      	previosTime = time;
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}