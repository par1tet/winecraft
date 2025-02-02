#include <glm/glm.hpp>
#include <vector>
#include "cube.hpp"

struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

AABB calculateAABB(Entity* cube);
bool checkCollisions(const std::vector<Entity*> objects);
