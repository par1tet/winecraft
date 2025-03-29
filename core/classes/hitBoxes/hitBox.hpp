#include <glm/vec3.hpp>
#include <string>
#include <iostream>
#include <vector>

#ifndef hitboxclass
#define hitboxclass

class HitBox {
public:
    HitBox(glm::vec3 position){
        this->position = position;
    }

    virtual bool checkCollision(const HitBox* otherHitBox){return false;}
    virtual std::vector<glm::vec3> resolveCollision(const HitBox* otherHitBox){return {glm::vec3{0.0f}};}

    glm::vec3 position;
};

class HitBoxAABB : public HitBox {
public:
    HitBoxAABB(glm::vec3 position, glm::vec3 size) : HitBox(position) {
        this->size = size;
    }

    bool checkCollision(const HitBox* otherHitBox);
    bool checkCollision(const HitBoxAABB* otherHitBox);
    std::vector<glm::vec3> resolveCollision(const HitBox* otherHitBox);
    std::vector<glm::vec3> resolveCollision(const HitBoxAABB* otherHitBox);

    glm::vec3 size;
};

#endif