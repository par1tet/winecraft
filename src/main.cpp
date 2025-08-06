#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <iterator>
#include "controls.hpp"
#include "createEntities.h"
#include <classes/worldKeeper/worldKeeper.hpp>
#include <classes/extensions/moveMentExtension.hpp>
#include <classes/extensions/positionExtension.hpp>
#include <classes/extensions/objectExtension.hpp>
#include <classes/worldKeeper/keyTrigger.hpp>
#include <classes/objects/cube.hpp>
#include <classes/extensions/collisionExtension/collisionExtension.hpp>
#include <classes/hitBox/hitBoxRect.hpp>
#include <classes/extensions/physicsExtension.hpp>
#include <thread>
#include <chrono>
#include <classes/entities/camera.hpp>

using namespace std;

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

    GLuint shaderProgram = createShaderProgram(
      	getAssetPath("shaders/vertex.glsl").c_str(),
      	getAssetPath("shaders/fragment.glsl").c_str()
    );

    GLdouble previosTime = 0.0f, delayTime = moveXY/targetFps;
    int fps;

    glEnable(GL_DEPTH_TEST);

	vector<Entity*> entitiesList;

	entitiesList.push_back(new Entity({new ObjectExtension(createCubeObjects({glm::vec3{0.0f}, glm::vec3{0.0f,2.5f,0.0f}, glm::vec3{0.0f,-2.5f,0.0f}}, 
									{glm::vec3{0.5f,4.0f,1.0f}, glm::vec3{2.0f,1.0f,1.0f}, glm::vec3{2.0f,1.0f,1.0f}})), 
        new CollisionExtension({new HitBoxRect(glm::vec3{0.0f}, glm::vec3{0.5f, 4.0f, 1.0f}),
                                new HitBoxRect(glm::vec3{0.0f, 2.5f, 0.0f}, glm::vec3{2.0f, 1.0f, 1.0f}),
                                new HitBoxRect(glm::vec3{0.0f, -2.5f, 0.0f}, glm::vec3{2.0f, 1.0f, 1.0f}),}, 1.0f, 0.5f), 
									new Position(glm::vec3{0.0f,0.0f,0.0f}),
            new PhysicsExtension(1.0f, 0.9f, 0.9f)
                }));


	entitiesList.push_back(new Entity({new ObjectExtension(
					createCubeObjects({glm::vec3{0.0f}, glm::vec3{0.0f,1.5f,0.0f}}, 
									{glm::vec3{3.0f,2.0f,1.0f}, glm::vec3{1.0f,1.0f,1.0f}})), 
        new CollisionExtension({new HitBoxRect(glm::vec3{0.0f,0.0f,0.0f}, glm::vec3{3.0f, 2.0f, 1.0f}),
                                new HitBoxRect(glm::vec3{0.0f, 1.5f, 0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}),}, 1.0f, 0.5f), new Position(glm::vec3{3.0f,3.0f,0.0f})}));

	entitiesList.push_back(createCube(glm::vec3{-3.0f, -3.0f, 0.0f}));

	Camera* camera = new Camera(glm::vec3(0.f,0.f,-30.f), 45.f);
	entitiesList.push_back(dynamic_cast<Entity*>(camera));

	WorldKeeper* worldKeeperObj = new WorldKeeper(entitiesList, window, new KeyTrigger(window));

	//std::cout << "lenght: " << entitiesList[3]->getExtension<Position>("PositionExtension")->getPosition().x << std::endl;

    GLuint modelMatrixLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
    GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
    GLuint projectionMatrixLocation = glGetUniformLocation(shaderProgram, "projectionMatrix");

    // Main loop : λι τνκ υζσλκ
    while (!glfwWindowShouldClose(window)) {
      	glfwPollEvents();
      	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);

		system("clear");

      	GLdouble time = glfwGetTime();

        if(previosTime == 0) previosTime = time;
		double frameTime = time - previosTime;
		if(frameTime < dt) {
			std::this_thread::sleep_for(std::chrono::duration<double>(dt - frameTime));
		}	

        worldKeeperObj->gameFrame(dt);

      	glm::mat4 viewMatrix = glm::mat4(1.0f);
      	viewMatrix = glm::translate(viewMatrix, camera->getPosition());

      	glm::mat4 projectionMatrix = camera->getProjectionMatrix();

    	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

		for(int i = 0;i < worldKeeperObj->getEntities().size(); i++){
			if(worldKeeperObj->getEntities()[i]->getExtensions().count("ObjectExtension") == 0){continue;}

			ObjectExtension* objExt = worldKeeperObj->getEntities()[i]->getExtension<ObjectExtension>("ObjectExtension");
			for(int j = 0;j < objExt->getObjects().size();j++){
				glm::mat4 modelMatrix = glm::mat4(1.0f);
    
				modelMatrix = glm::translate(modelMatrix, worldKeeperObj->getEntities()[i]->getExtension<ObjectExtension>("ObjectExtension")->getAbsolutePosition(worldKeeperObj->getEntities()[i], j));

				glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
			 	worldKeeperObj->getEntities()[i]->getExtension<ObjectExtension>("ObjectExtension")->getObjects()[j]->drawObject(shaderProgram);
			}
		}

        fps = 1 / (time-previosTime);
      	glfwSwapBuffers(window);
      	previosTime = time;
    }

    glfwTerminate();
    return 0;
}
