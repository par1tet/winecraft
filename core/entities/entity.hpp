#include <glm/glm.hpp>
#include <string>
#include <objects/object.hpp>
#include <hitBoxes/collision.hpp>
#include <vector>

class Entity {
public:
    Entity(glm::vec3 position, std::vector<Object*> objects, Collision *collision): _collision(collision) {
        this->position = position;
        this->objects = objects;
    }

    Entity(const Entity &other): _collision(other._collision){
        position = other.position;
        objects = other.objects;
    }

    void changePosition(glm::vec3 dPos){
        position += dPos;
        for(int i = 0;i != objects.size();i++){
            objects[i]->position += dPos;
        }
        for(int i = 0;i != _collision->hitBoxes.size();i++){
            _collision->hitBoxes[i]->position += dPos;
        }
    }

    glm::vec3 position;
    std::vector<Object*> objects;
    Collision *_collision;
};

