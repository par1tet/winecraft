#include <glm/glm.hpp>
#include <classes/entities/entity.hpp>

#pragma once

class HitBoxRect;

class HitBox{
private:
    glm::vec3 position;

public:
    HitBox(glm::vec3 position);
    virtual ~HitBox() = default;

    virtual glm::vec3 collisionWith(HitBox* otherHitBox, Entity*, Entity*) const = 0;
    virtual glm::vec3 collisionWithRect(const HitBoxRect* otherHitBox, Entity*, Entity*) const;
    virtual glm::vec3 getPosition() const;
    virtual glm::vec3 getAbsolutePositioin(Entity*) const;
};
