#include<classes/extensions/extension.hpp>
#include <classes/hitBox/hitBox.hpp>
#include <glm/fwd.hpp>
#include <string>
#include <vector>
#include <classes/entities/entity.hpp>

#pragma once

class CollisionExtension : public Extension {
private:
    std::vector<HitBox*> hitBoxes;
    float mass;
    float elasticity;

public:
    CollisionExtension(std::vector<HitBox*> hitBoxes, float mass, float elasticity);
    CollisionExtension(std::vector<HitBox*>);

    void checkCollision(CollisionExtension* otherCollision, Entity*, Entity*);
    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    void gameInit(GLFWwindow* window);
    glm::vec3 getAbsolutePosition(Entity*, int);
    std::vector<HitBox*> getHitBoxes();
    float getElasticity();

    std::string getExName();
    float getMass();
};
