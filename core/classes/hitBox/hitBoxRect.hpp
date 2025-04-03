#include <glm/glm.hpp>
#include <classes/hitBox/hitBox.hpp>

#pragma once

class HitBoxRect : public HitBox{
private:
    glm::vec3 size;
    glm::vec3 position;
public:
    HitBoxRect(glm::vec3 position, glm::vec3 size);

    bool collisionWith(HitBox* otherHitBox, Entity*, Entity*);
    bool collisionWithRect(HitBoxRect* otherHitBox, Entity*, Entity*);
    glm::vec3 getSize();
};
