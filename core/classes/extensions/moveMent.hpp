#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<string.h>
#include<glm/glm.hpp>

#ifndef moveMentClass
#define moveMentClass

class MoveMent : public Extension {
public:
    MoveMent() : Extension() {
        
    }

    void gameInit(GLFWwindow* window);
    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    std::string getExName(){return "MoveMent";}

    glm::vec3 moveVector;
    int maxSpeed;
    int runUpTime;
};


#endif