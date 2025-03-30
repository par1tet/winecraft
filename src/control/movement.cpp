#include "controls.hpp"
#include <GLFW/glfw3.h>
#include <vector>
using namespace std;

void handleMoves(vector<Entity*> entitiesList, int countCubes) {
	vector<int> backPos;
	vector<int> indexEntity;

	// if (PressedW) {
	// 	entitiesList[0]->changePosition(glm::vec3{0.0f, moveXY, 0.0f});
	// 	backPos.push_back(1);
	// 	indexEntity.push_back(0);
	// }
	// if (PressedS) {
	// 	entitiesList[0]->changePosition(glm::vec3{0.0f, -moveXY, 0.0f});
	// 	backPos.push_back(1);
	// 	indexEntity.push_back(0);
	// }
	// if (PressedA) {
	// 	entitiesList[0]->changePosition(glm::vec3{-moveXY, 0.0f, 0.0f});
	// 	backPos.push_back(0);
	// 	indexEntity.push_back(0);
	// }

	// if (PressedD) {
	// 	entitiesList[0]->changePosition(glm::vec3{moveXY, 0.0f, 0.0f});
	// 	backPos.push_back(0);
	// 	indexEntity.push_back(0);
	// }

	if (PressedUp) {
		entitiesList[1]->changePosition(glm::vec3{0.0f, moveXY, 0.0f});
		backPos.push_back(1);
		indexEntity.push_back(1);
	}
	if (PressedDown) {
		entitiesList[1]->changePosition(glm::vec3{0.0f, -moveXY, 0.0f});
		backPos.push_back(1);
		indexEntity.push_back(1);
	}
	if (PressedLeft) {
		entitiesList[1]->changePosition(glm::vec3{-moveXY, 0.0f, 0.0f});
		backPos.push_back(0);
		indexEntity.push_back(1);
	}
	if (PressedRight) {
		entitiesList[1]->changePosition(glm::vec3{moveXY, 0.0f, 0.0f});
		backPos.push_back(0);
		indexEntity.push_back(1);
	}

	for(int i = 0;i != entitiesList.size();i++){
		for(int j = i+1;j != entitiesList.size();j++){
			if(i == j) continue;

			entitiesList[i]->_collision->resolveCollision(entitiesList[j]->_collision);
		}
	}
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
  	// if (key == GLFW_KEY_W) {
	// 	if (action == GLFW_PRESS) {
	//   		PressedW = true;
	// 	} else if (action == GLFW_RELEASE) {
	//   		PressedW = false;
	// 	}
  	// }

  	// if (key == GLFW_KEY_S) {
	// 	if (action == GLFW_PRESS) {
	//   		PressedS = true;
	// } else if (action == GLFW_RELEASE) {
	//   		PressedS = false;
	// 	}
  	// }

  	// if (key == GLFW_KEY_A) {
	// 	if (action == GLFW_PRESS) {
	//   		PressedA = true;
	// 	} else if (action == GLFW_RELEASE) {
	//   		PressedA = false;
    //         		}
  	// }

	// if (key == GLFW_KEY_D) {
	// 	if (action == GLFW_PRESS) {
	//   		PressedD = true;
	// 	} else if (action == GLFW_RELEASE) {
	//   		PressedD = false;
	// 	}
  	// }

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

