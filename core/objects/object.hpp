#include <glm/glm.hpp>
#include <string>
#include <iostream>

class Object {
public:
    Object(glm::vec3 position, std::string texturePath){
        this->position = position;
        this->texturePath = texturePath;
    }

    virtual void printPosition(){
        std::cout << "x:\t" << position.x << "y:\t" << position.y << "z: " << position.z << std::endl;
    }

    glm::vec3 position;
    std::string texturePath;
};

class Cube : public Object {
public:
    Cube(glm::vec3 position, std::string texturePath, glm::vec3 size) : Object(position, texturePath){
        this->size = size;
    }

    glm::vec3 position;
    std::string texturePath;
    glm::vec3 size;
};