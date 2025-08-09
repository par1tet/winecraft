#pragma once

#include<classes/extensions/positionExtension.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<GLFW/glfw3.h>

class RotateCameraExtension : public Extension {
private:
    float sens;
    float lastX, lastY;
    float pitch, yaw;
    glm::vec3 direction;
    glm::vec3 upVector;
    glm::mat4 viewMatrix;
    GLFWwindow* window;
    int enId;
    WorldKeeper* worldKeeper;

public:
    RotateCameraExtension(float sens, GLFWwindow* window, Position* positionEntity);

    static void keyCallbackDispatcherMouse(GLFWwindow* window, double xpos, double ypos);
    void dirHandler(double xpos, double ypos);
    void gameFrame();
    std::string getExName();
    glm::mat4 getViewMatrix();
};
