#include <glm/vec3.hpp>
#include "entities/entity.hpp"
#include <string>

class Cube : public Entity {
public:
    Cube(glm::vec3 entityPosition, std::string entityTexturePath, float cube_size)
        : Entity(entityPosition, entityTexturePath, cube_size) {
        position = entityPosition;
        texturePath = entityTexturePath;
        size = cube_size;
    }

    glm::vec3 position;
    std::string texturePath;
    float size; // Теперь нет конфликта имен
};