#include <glm/glm.hpp>
#include <string>
#include <iostream>

#ifndef objectclass
#define objectclass

class Object {
public:
    Object(glm::vec3 position, std::string texturePath){
        this->position = position;
        this->texturePath = texturePath;
    }

    virtual void printPosition();

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

#endif