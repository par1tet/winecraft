#pragma once

#include <glm/glm.hpp>
#include <classes/hitBox/hitBox.hpp>

class HitBoxRect : public HitBox{
private:
    glm::vec3 size;
    glm::vec3 position;
public:
    HitBoxRect(glm::vec3 position, glm::vec3 size);

    glm::vec3 collisionWith(HitBox* otherHitBox, Entity*, Entity*) const override;
    glm::vec3 collisionWithRect(const HitBoxRect* otherHitBox, Entity*, Entity*) const override;
    glm::vec3 getSize() const;
};
