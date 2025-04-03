#include <glm/glm.hpp>
#include <classes/entities/entity.hpp>

#pragma once

class HitBoxRect;

class HitBox{
private:
    glm::vec3 position;

public:
    HitBox(glm::vec3 position);

    virtual bool collisionWith(HitBox* otherHitBox, Entity*, Entity*);
    virtual bool collisionWithRect(HitBoxRect* otherHitBox, Entity*, Entity*);
    virtual glm::vec3 getPosition();
    virtual glm::vec3 getAbsolutePositioin(Entity*);
};
