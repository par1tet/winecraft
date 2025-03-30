#include <glm/glm.hpp>
#include <string>
#include <classes/objects/object.hpp>
#include <classes/hitBoxes/collision.hpp>
#include <vector>
#include <unordered_map>
#include <GLFW/glfw3.h>

#ifndef entityclass
#define entityclass

class Extension;

class Entity {
public:
    Entity(Collision *collision, std::vector<Extension*> extensions);

    Entity(const Entity &other): _collision(other._collision){
    }

    void changePosition(glm::vec3 dPos);
    void gameInit(GLFWwindow* window);
    template<class T>
    T* getExtension(std::string exName);

    Collision *_collision;
    std::unordered_map<std::string, Extension*> extensions;
    std::vector<std::string> extensionsNames;
};

#endif