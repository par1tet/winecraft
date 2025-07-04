#pragma once

#include <glm/glm.hpp>
#include <string>
#include <classes/objects/object.hpp>
#include <vector>
#include <unordered_map>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

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

template <class T> 
T* Entity::getExtension(std::string exName){
    T* converted = dynamic_cast<T*>(this->extensions[exName]);

    return converted;
}
