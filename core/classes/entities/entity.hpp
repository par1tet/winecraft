#include <glm/glm.hpp>
#include <string>
#include <classes/objects/object.hpp>
#include <classes/hitBoxes/collision.hpp>
#include <vector>
#include <unordered_map>
#include <GLFW/glfw3.h>

#pragma once

class Extension;

class Entity {
private:
    std::unordered_map<std::string, Extension*> extensions;
    std::vector<std::string> extensionsNames;

public:
    Entity(std::vector<Extension*> extensions);

    void changePosition(glm::vec3 dPos);
    void gameInit(GLFWwindow* window);
    template<class T>
    T* getExtension(std::string exName);

    std::vector<std::string> getExtensionsNames();
    std::unordered_map<std::string, Extension*> getExtensions();
};