#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<glm/glm.hpp>

#ifndef moveMentClass
#define moveMentClass

class MoveMent : public Extension {
private:
    glm::vec3 moveVector = glm::vec3(0.0f);
    double maxSpeed;
    double runUpTime;

public:
    MoveMent(double maxSpeed, double runUpTime);

    void gameInit(GLFWwindow* window);
    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    std::string getExName();
};


#endif