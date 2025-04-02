#include<classes/extensions/extension.hpp>
#include <classes/hitBox/hitBox.hpp>
#include <string>
#include <vector>

#pragma once

class CollisionExtension : public Extension {
private:
    std::vector<HitBox*> hitBoxes;

public:
    CollisionExtension(std::vector<HitBox*> hitBoxes);

    bool checkCollision(CollisionExtension* otherCollision);
    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    void gameInit(GLFWwindow* window);

    std::string getExName();
};
