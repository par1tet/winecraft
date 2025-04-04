#include <glm/glm.hpp>
#include <classes/entities/entity.hpp>

#pragma once

class HitBoxRect;

class HitBox{
private:
    glm::vec3 position;

public:
    HitBox(glm::vec3 position);

    virtual void collisionWith(HitBox* otherHitBox, Entity*, Entity*);
    virtual void collisionWithRect(HitBoxRect* otherHitBox, Entity*, Entity*);
    virtual glm::vec3 getPosition();
    virtual glm::vec3 getAbsolutePositioin(Entity*);
};
