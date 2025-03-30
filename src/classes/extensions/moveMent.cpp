#include<classes/extensions/moveMent.hpp>
#include<classes/entities/entity.hpp>
#include<classes/extensions/position.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>

inline bool PressedW= false;
inline bool PressedS= false;
inline bool PressedA= false;
inline bool PressedD= false;

void key_callbackMove(GLFWwindow *window, int key, int scancode, int action, int mode);

void MoveMent::gameInit(GLFWwindow* window){
    glfwSetKeyCallback(window, key_callbackMove);
}

void MoveMent::gameFrame(WorldKeeper* worldKeeperCl, int enId){
    Entity* thisEntity = worldKeeperCl->entities[enId];

    if(PressedW)
        dynamic_cast<Position*>(thisEntity->extensions["Position"])->position = glm::vec3{1.0f};
}


void key_callbackMove(GLFWwindow *window, int key, int scancode, int action, int mode) {
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