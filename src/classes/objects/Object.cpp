#include <classes/objects/object.hpp>
#include <iostream>
#include <string>
#include <glm/glm.hpp>

Object::Object(glm::vec3 position, std::string texturePath){
    this->position = position;
    this->texturePath = texturePath;
}

void Object::printPosition(){
    std::cout << "x:\t" << position.x << "y:\t" << position.y << "z: " << position.z << std::endl;
}

glm::vec3 Object::getPosition(){
    return position;
}