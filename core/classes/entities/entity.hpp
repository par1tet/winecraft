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
private:
    Collision *collision;
    std::unordered_map<std::string, Extension*> extensions;
    std::vector<std::string> extensionsNames;

public:
    Entity(Collision *collision, std::vector<Extension*> extensions);

    void changePosition(glm::vec3 dPos);
    void gameInit(GLFWwindow* window);
    template<class T>
    T* getExtension(std::string exName);

    Collision* getCollision();
    std::vector<std::string> getExtensionsNames();
    std::unordered_map<std::string, Extension*> getExtensions();
};

#endif