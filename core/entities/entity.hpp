#include <glm/glm.hpp>




class Entity {
public:
    // Конструктор Entity с параметрами
    Entity(glm::vec3 entityPosition, char* entityTexturePath, float entitySize)
        : position(entityPosition), texturePath(entityTexturePath), size(entitySize) {

        }

    glm::vec3 position;
    char* texturePath;
    float size;
};

