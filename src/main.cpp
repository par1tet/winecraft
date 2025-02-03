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
#include "assets.h"
#include "controls.hpp"

using namespace std;

const float moveXY = 0.1f;

vector<Entity*> deepCopy(vector<Entity*> arrayForCopy){
	vector<Entity*> arrayCopy;

	for(int i = 0;i != arrayForCopy.size();i++){
		arrayCopy.push_back(new Entity(*(arrayForCopy[i])));
	}

	return arrayCopy;
}


vector<Entity*> handleMoves(vector<Entity*> entitiesList, int countCubes) {
	//vector<AABB> collisionObjects;

	vector<Entity*> newEntitiesList = deepCopy(entitiesList);

	if (PressedW) {
		newEntitiesList[0]->changePosition(glm::vec3{0.0f, moveXY, 0.0f});
	}
	if (PressedS) {
		newEntitiesList[0]->changePosition(glm::vec3{0.0f, -moveXY, 0.0f});
	}
	if (PressedA) {
		newEntitiesList[0]->changePosition(glm::vec3{-moveXY, 0.0f, 0.0f});
	}
	if (PressedD) {
		newEntitiesList[0]->changePosition(glm::vec3{moveXY, 0.0f, 0.0f});
	}

	if (PressedUp) {
		newEntitiesList[1]->position[1] += moveXY;
	}
	if (PressedDown) {
		newEntitiesList[1]->position[1] -= moveXY;
	}
	if (PressedLeft) {
		newEntitiesList[1]->position[0] -= moveXY;
	}
	if (PressedRight) {
		newEntitiesList[1]->position[0] += moveXY;
	}

	cout << newEntitiesList[0]->position[0] << " : " << entitiesList[0]->position[0] << endl;

	if(false) {
		return entitiesList;
	}

	return newEntitiesList;
}

int main() {
	std::vector<Object*> objects;
	objects.push_back(new Cube(glm::vec3(0.0f,0.0f,0.0f), "assets/textures/murych_cat.png", glm::vec3(3.0f, 1.0f, 1.0f)));

	vector<HitBox> hitBoxes;
	hitBoxes.push_back(HitBoxAABB(glm::vec3{0.0f, 0.0f, 0.0f}, glm::vec3{3.0f, 1.0f, 1.0f}));

	Collision collision{hitBoxes};

	entitiesList.push_back(new Entity(glm::vec3(0.0f,0.0f,0.0f), objects, collision));

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


      	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
      	glClear(GL_COLOR_BUFFER_BIT);

      	glUseProgram(shaderProgram);

      	glm::mat4 viewMatrix = glm::mat4(1.0f);
      	viewMatrix = glm::translate(viewMatrix, glm::vec3(0.0f, 0.0f, -40.0f));

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

		for(int i = 0;i < entitiesList.size(); i++){
			for(int j = 0;j < entitiesList[i]->objects.size();j++){
				glm::mat4 modelMatrix = glm::mat4(1.0f);
				modelMatrix = glm::translate(modelMatrix, entitiesList[i]->objects[j]->position);
			
				glm::mat4 trans = glm::mat4(1.0f);
				trans = glm::translate(trans, entitiesList[i]->objects[j]->position);
				
				float color[] = {(float)i, 1.0f, 1.0f, 1.0f};

				glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
				glUniformMatrix4fv(transLocation, 1, GL_FALSE, glm::value_ptr(trans));
				glUniform4fv(colorLocation, 1, color);
				glUniform3fv(sizeLocation, 1, glm::value_ptr(((dynamic_cast<Cube*>((entitiesList[i])->objects[j])))->size));

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}
		}
	
		if(time - previosTimeDelay >= delayTime){
			entitiesList = handleMoves(entitiesList, entitiesList.size());
			previosTimeDelay = time;
		}

        fps = 1 / (time-previosTime);
      	glBindVertexArray(0);
      	glfwSwapBuffers(window);
      	previosTime = time;
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}
