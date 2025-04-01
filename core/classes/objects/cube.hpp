#include<classes/objects/object.hpp>

#pragma once

class Cube : public Object {
private:
    glm::vec3 position;
    std::string texturePath;
    glm::vec3 size;

public:
    Cube(glm::vec3 position, std::string texturePath, glm::vec3 size);

    glm::vec3 getSize();
};