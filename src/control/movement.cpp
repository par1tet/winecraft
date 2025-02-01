#include "controls.hpp"
#include <GLFW/glfw3.h>


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

