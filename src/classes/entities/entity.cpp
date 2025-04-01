#include <classes/entities/entity.hpp>
#include <classes/extensions/extension.hpp>
#include <classes/extensions/object.hpp>
#include <classes/extensions/position.hpp>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string.h>
#include <stdio_ext.h>
#include <unordered_map>

Entity::Entity(Collision *collision, std::vector<Extension*> extensions): collision(collision) {
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

template <class T> 
T* Entity::getExtension(std::string exName){
    T* converted = dynamic_cast<T*>(this->extensions[exName]);

    if(converted){
        return converted;
    }else{
        throw std::runtime_error("Жидкие ясели не работают с питонами");
    }
}

Collision* Entity::getCollision(){
    return collision;
}

std::unordered_map<std::string, Extension*> Entity::getExtensions(){
    return extensions;
}

std::vector<std::string> Entity::getExtensionsNames(){
    return extensionsNames;
}