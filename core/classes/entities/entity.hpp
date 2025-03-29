#include <glm/glm.hpp>
#include <string>
#include <classes/objects/object.hpp>
#include <classes/hitBoxes/collision.hpp>
#include <vector>
#include <classes/extensions/extension.hpp>

#ifndef entityclass
#define entityclass

class Entity {
public:
    Entity(glm::vec3 position, std::vector<Object*> objects, Collision *collision, std::vector<Extension*> extensions): _collision(collision) {
        this->position = position;
        this->objects = objects;
        this->extensions = extensions;
    }

    Entity(const Entity &other): _collision(other._collision){
        position = other.position;
        objects = other.objects;
    }

    void changePosition(glm::vec3 dPos);

    glm::vec3 position;
    std::vector<Object*> objects;
    Collision *_collision;
    std::vector<Extension*> extensions;
};

#endif