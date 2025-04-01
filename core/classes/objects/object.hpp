#include <glm/glm.hpp>
#include <string>
#include <iostream>

#ifndef objectclass
#define objectclass

class Object {
private:
    glm::vec3 position;
    std::string texturePath;

public:
    Object(glm::vec3 position, std::string texturePath);

    virtual void printPosition();

    virtual glm::vec3 getPosition();
};

#endif