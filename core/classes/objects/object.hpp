#pragma once

#include <glm/glm.hpp>
#include <string>
#include <iostream>
#include <vars.hpp>
#define GLFW_INCLUDE_NONE
#include<GLFW/glfw3.h>

class Object {
private:
    glm::vec3 position;
    std::string texturePath;

public:
    Object(glm::vec3 position, std::string texturePath);

    virtual void printPosition();

    virtual glm::vec3 getPosition();
    virtual void drawObject(GLuint shaderProgram);
};