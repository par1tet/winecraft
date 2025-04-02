#pragma once

class HitBoxRect;

class HitBox{
public:
    virtual bool collisionWith(HitBox* otherHitBox);
    virtual bool collisionWithRect(HitBoxRect* otherHitBox);
};
