#include "assets.h"
#include <glm/glm.hpp>
#include <iostream>
#include <string>

std::string getAssetPath(const std::string &relativePath) {
  	return std::string(ASSET_PATH) + relativePath;
}

void printGLMVector(glm::vec3 vec){
    std::cout << "x: " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;
}
