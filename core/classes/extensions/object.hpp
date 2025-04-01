#include<classes/extensions/extension.hpp>
#include<classes/worldKeeper/worldKeeper.hpp>
#include<classes/entities/entity.hpp>
#include<string.h>
#include<GLFW/glfw3.h>
#include<classes/objects/object.hpp>
#include<vector>
#include<glm/glm.hpp>

#ifndef objectExtensionClass
#define objectExtensionClass

class ObjectExtension : public Extension {
private:
    std::vector<Object*> objects;

public:
    ObjectExtension(std::vector<Object*> objects);

    void gameFrame(WorldKeeper* worldKeeperCl, int enId){}
    void gameInit(GLFWwindow* window){}
    std::string getExName();
    glm::vec3 getAbsolutePosition(Entity*, int);

    std::vector<Object*> getObjects();
};


#endif