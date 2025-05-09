#include <classes/entities/entity.hpp>
#include <classes/extensions/extension.hpp>
#include <classes/extensions/objectExtension.hpp>
#include <classes/extensions/positionExtension.hpp>
#include <classes/extensions/collisionExtension/collisionExtension.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdio_ext.h>
#include <unordered_map>

Entity::Entity(std::vector<Extension*> extensions) {
    for(int i = 0;i != extensions.size();i++){
        this->extensionsNames.push_back(extensions[i]->getExName());
        this->extensions[this->extensionsNames[i]] = extensions[i];
    }
}

void Entity::changePosition(glm::vec3 dPos){
    for(int i = 0;i != this->getExtension<ObjectExtension>("ObjectExtension")->getObjects().size();i++){
        this->getExtension<Position>("Position")->changePosition(dPos);
    }
}

void Entity::gameInit(GLFWwindow* window){
    for(int i = 0;i != this->extensionsNames.size();i++){
        this->extensions[this->extensionsNames[i]]->gameInit(window);
    }
}


std::unordered_map<std::string, Extension*> Entity::getExtensions(){
    return extensions;
}

std::vector<std::string> Entity::getExtensionsNames(){
    return extensionsNames;
}
