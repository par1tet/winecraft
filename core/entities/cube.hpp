#include <glm/vec3.hpp>
#include "entities/entity.hpp"

class Cube : public Entity {
public:
    Cube(glm::vec3 entityPosition, char* entityTexturePath, float cube_size)
        : Entity(entityPosition, entityTexturePath, cube_size) {
        position = entityPosition;
        texturePath = entityTexturePath;
        size = cube_size;
    }

    glm::vec3 position;
    char* texturePath;
    float size; // Теперь нет конфликта имен
};