#pragma once

#include<classes/extensions/extension.hpp>
#include <glm/fwd.hpp>
#include <string>

class PhysicsExtension : public Extension {
private:
    float mass;
    float maxSpeed;
    float elasticity;
    float friction;

public:
    PhysicsExtension(float mass, float elasticity, float friction);

    void gameFrame(float dTime, WorldKeeper *worldKeeperCl, int enId);

    std::string getExName(){return "PhysicsExtension";}
};
