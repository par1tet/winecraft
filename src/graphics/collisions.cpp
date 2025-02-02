#include <glm/vec3.hpp>
#include <collisions.h>
#include <iostream>
#include <math.h>
#include <vector>

AABB calculateAABB(Entity* hitBox) {
    AABB box;
    box.min = hitBox->position - glm::vec3(hitBox->size / 2.0f);
    box.max = hitBox->position + glm::vec3(hitBox->size / 2.0f);
    return box;
}

bool isColliding(const AABB& a, const AABB& b) {
    return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
           (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
           (a.min.z <= b.max.z && a.max.z >= b.min.z);
}

bool checkCollisions(std::vector<Entity*> objects) {
    std::vector<AABB> hitBoxes;

    for(int i = 0;i != objects.size();i++){
        hitBoxes.push_back(calculateAABB(objects[i]));
    }

    for (size_t i = 0; i < objects.size(); ++i) {
        for (size_t j = i + 1; j < objects.size(); ++j) {
            if (isColliding(hitBoxes[i], hitBoxes[j])){
                std::cout << "collisions worked" << std::endl; 
            return true;
            }
        }
    }
    return false;
}
