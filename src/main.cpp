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
#include <collisions.hpp>

using namespace std;

bool PressedW = false;
bool PressedS = false;
bool PressedA = false;
bool PressedD = false;
bool PressedUp = false;
bool PressedLeft = false;
bool PressedRight = false;
bool PressedDown = false;

const float moveXY = 0.1f;

bool isCollision(){
    return true;
}
void handleMoves() {
    if (isCollision()){
       	if (PressedW) {
            cubeCoordinates[0][1] += moveXY;
       	}
       	if (PressedS) {
            cubeCoordinates[0][1] -= moveXY;
       	}
       	if (PressedA) {
            cubeCoordinates[0][0] -= moveXY;
       	}
       	if (PressedD) {
            cubeCoordinates[0][0] += moveXY;
       	}
    }

	if(isCollision()){
	    if (PressedUp) {
			cubeCoordinates[1][1] += moveXY;
		}
  	    if (PressedDown) {
           cubeCoordinates[1][1] -= moveXY;
      	}
      	if (PressedLeft) {
           cubeCoordinates[1][0] -= moveXY;
      	}
      	if (PressedRight) {
           cubeCoordinates[1][0] += moveXY;
      	}
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

	if (key == GLFW_KEY_UP) {
		if (action == GLFW_PRESS) {
	  		PressedUp = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedUp = false;
		}
  	}

	if (key == GLFW_KEY_LEFT) {
		if (action == GLFW_PRESS) {
	  		PressedLeft = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedLeft = false;
		}
  	}

  	if (key == GLFW_KEY_RIGHT) {
		if (action == GLFW_PRESS) {
	  		PressedRight = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedRight = false;
		}
  	}

  	if (key == GLFW_KEY_DOWN) {
		if (action == GLFW_PRESS) {
	  		PressedDown = true;
		} else if (action == GLFW_RELEASE) {
	  		PressedDown = false;
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

      	if(time - previosTimeDelay >= delayTime){
      		handleMoves();
      		previosTimeDelay = time;
      	}

      	fps = 1 / (time-previosTime);
      	system("clear");
      	cout << fps << endl;

      	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
      	glClear(GL_COLOR_BUFFER_BIT);

      	glUseProgram(shaderProgram);

      	glm::mat4 viewMatrix = glm::mat4(1.0f);
      	glm::mat4 projectionMatrix = glm::mat4(1.0f);

      	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -10.0f));
      	projectionMatrix = glm::perspective(glm::radians(45.0f), float(width/height), 0.1f, 100.0f);

      	GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
      	GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
      	GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");
      	GLuint transLocation = glGetUniformLocation(shaderProgram, "transform");
      	GLuint colorLocation = glGetUniformLocation(shaderProgram, "colorCube");

      	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
      	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

      	glUseProgram(shaderProgram);
      	glBindTexture(GL_TEXTURE_2D, texture);

      	glBindVertexArray(VAO);

        for(int i = 0;i <= 1;i++){
      		glm::mat4 modelMatrix = glm::mat4(1.0f);
        	modelMatrix = glm::translate(modelMatrix, cubePositions[i]);

      		glm::mat4 trans = glm::mat4(1.0f);
      		trans = glm::translate(trans, glm::vec3(cubeCoordinates[i][0], cubeCoordinates[i][1], 0.0f));

        float color[] = {(float)i, 1.0f, 1.0f, 1.0f};

      		glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
      		glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(trans));
        	glUniform4fv(colorLocation, 1, color);

      		glDrawArrays(GL_TRIANGLES, 0, 36);
		}

      	glBindVertexArray(0);
      	glfwSwapBuffers(window);
      	previosTime = time;
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
