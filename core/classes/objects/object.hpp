#include <glm/glm.hpp>
#include <string>
#include <iostream>

#pragma once

class Object {
private:
    glm::vec3 position;
    std::string texturePath;

public:
    Object(glm::vec3 position, std::string texturePath);

    virtual void printPosition();

    virtual glm::vec3 getPosition();
};