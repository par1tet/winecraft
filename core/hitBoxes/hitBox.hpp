#include <glm/vec3.hpp>
#include <string>

class HitBox {
public:
    HitBox(glm::vec3 position){
        this->position = position;
    }

    bool checkCollision(const HitBox &OtherHitBox){return false;}

    glm::vec3 position;
};

class HitBoxAABB : public HitBox {
public:
    HitBoxAABB(glm::vec3 position, glm::vec3 size) : HitBox(position) {
        this->size = size;
    }

    bool checkCollision(const HitBoxAABB &OtherHitBox){
        return false;
    }

    glm::vec3 size;
};