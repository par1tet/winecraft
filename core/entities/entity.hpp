#include <glm/glm.hpp>
#include <string>

class Entity {
public:
    // Конструктор Entity с параметрами
    Entity(glm::vec3 entityPosition, std::string entityTexturePath, float entitySize)
        : position(entityPosition), texturePath(entityTexturePath), size(entitySize) {

        }

    glm::vec3 position;
    std::string texturePath;
    float size;
};

