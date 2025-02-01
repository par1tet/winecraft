#include <glm/vec3.hpp>
#include <collisions.h>
#include <math.h>


AABB calculateAABB(const glm::vec3& position, float size) {
    AABB box;
    box.min = position - glm::vec3(size / 2.0f);
    box.max = position + glm::vec3(size / 2.0f);
    return box;
}

bool checkCollision(const AABB& box1, const AABB& box2) {
    return (box1.min.x <= box2.max.x && box1.max.x >= box2.min.x) &&
           (box1.min.y <= box2.max.y && box1.max.y >= box2.min.y) &&
           (box1.min.z <= box2.max.z && box1.max.z >= box2.min.z);
}
