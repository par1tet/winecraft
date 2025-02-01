#include <glm/glm.hpp>

struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

AABB calculateAABB(const glm::vec3& position, float size);
bool checkCollision(const AABB& box1, const AABB& box2);
