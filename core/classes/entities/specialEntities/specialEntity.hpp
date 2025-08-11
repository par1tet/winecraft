#pragma once

#include<classes/entities/entity.hpp>

class SpecialEntity{
private:
    Entity* linkedEntity;
public:
    void gameFrame();
};