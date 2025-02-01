#include <glm/vec3.hpp>
#include <collisions.h>
#include <iostream>
#include <math.h>


AABB calculateAABB(const glm::vec3& position, float size) {
    AABB box;
    box.min = position - glm::vec3(size / 2.0f);
    box.max = position + glm::vec3(size / 2.0f);
    return box;
}

bool isColliding(const AABB& a, const AABB& b) {
    return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
           (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
           (a.min.z <= b.max.z && a.max.z >= b.min.z);
}

bool checkCollisions(const std::vector<AABB>& objects) {
    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
          if (isColliding(objects[i], objects[j])){
            std::cout << "collisions worked" << std::endl; 
            return true;
         }
        }
    }
    return false;
}
