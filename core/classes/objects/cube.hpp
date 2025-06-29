#pragma once

#include<classes/objects/object.hpp>
#include<glm/glm.hpp>
#include<string>
#include<assets.h>
#include<shader_utils.h>
#include<glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube : public Object {
private:
    glm::vec3 position;
    std::string texturePath;
    glm::vec3 size;
    GLuint VAO, VBO, EBO, TBO, texture;

public:
    Cube(glm::vec3 position, std::string texturePath, glm::vec3 size);

    glm::vec3 getSize();
    void drawObject(GLuint shaderProgram);
};