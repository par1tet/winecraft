#include <glm/glm.hpp>
#include <vector>

struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

AABB calculateAABB(const glm::vec3& position, float size);
bool checkCollisions(const std::vector<AABB>& objects);
