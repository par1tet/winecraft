#include <glm/glm.hpp>
#include <string>

class Entity {
public:
    Entity(glm::vec3 entityPosition, std::string entityTexturePath, float entitySize)
        : position(entityPosition), texturePath(entityTexturePath), size(entitySize) {

        }

    Entity(const Entity &other){
        position = other.position;
        size = other.size;
        texturePath = other.texturePath;
    }

    glm::vec3 position;
    std::string texturePath;
    float size;
};

