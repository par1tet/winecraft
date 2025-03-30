#include<classes/extensions/extension.hpp>
#include<classes/entities/entity.hpp>
#include<string.h>
#include<glm/glm.hpp>

#ifndef positionClass
#define positionClass

class Position : public Extension {
public:
    Position(glm::vec3 position) : Extension() {
        this->position = position;
    }

    void gameFrame(WorldKeeper* worldKeeperCl, int enId);
    std::string getExName(){return "Position";}

    glm::vec3 position;
};


#endif