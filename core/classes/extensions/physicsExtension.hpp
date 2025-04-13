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
    PhysicsExtension(float mass, float maxSpeed, float elasticity, float friction);

    void gameFrame(WorldKeeper *worldKeeperCl, int enId);

    std::string getExName(){return "PhysicsExtension";}
};
