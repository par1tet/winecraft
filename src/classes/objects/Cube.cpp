#include<classes/objects/cube.hpp>
#include<glm/glm.hpp>
#include<string>

Cube::Cube(glm::vec3 position, std::string texturePath, glm::vec3 size) : Object(position, texturePath){
    this->size = size;
}

glm::vec3 Cube::getSize(){
    return size;
}