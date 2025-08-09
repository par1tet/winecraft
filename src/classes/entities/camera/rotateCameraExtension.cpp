#include<classes/entities/camera/rotateCameraExtension.hpp>

RotateCameraExtension::RotateCameraExtension(float sens, GLFWwindow* window, Position* positionEntity) : Extension() {
    this->lastX = width / 2;
    this->lastY = height / 2;

    this->yaw = -90.f;
    this->pitch = 0.f;
    this->sens = sens;

    this->enId = enId;
    this->worldKeeper = worldKeeper;

    glm::vec3 front;

    front.x = cos(glm::radians(this->pitch)) * cos(glm::radians(this->yaw));
    front.y = sin(glm::radians(this->pitch));
    front.z = cos(glm::radians(this->pitch)) * sin(glm::radians(this->yaw));

    this->direction = glm::normalize(front);
    this->upVector = glm::vec3(0,1,0);

    this->viewMatrix = glm::lookAt(positionEntity->getPosition(), positionEntity->getPosition() + this->direction, this->upVector);

    glfwSetCursorPosCallback(window, this->keyCallbackDispatcherMouse);
}

void RotateCameraExtension::gameFrame(){
    std::cout << "chileee" << std::endl;

    Position* positionEntity = this->worldKeeper->getEntities()[enId]->getExtension<Position>("PositionExtension");
    
    glm::vec3 front;
    front.x = cos(glm::radians(this->pitch)) * cos(glm::radians(this->yaw));
    front.y = sin(glm::radians(this->pitch));
    front.z = cos(glm::radians(this->pitch)) * sin(glm::radians(this->yaw));
    this->direction = glm::normalize(front);

    this->viewMatrix = glm::lookAt(positionEntity->getPosition(), positionEntity->getPosition() + this->direction, this->upVector);
}

void RotateCameraExtension::keyCallbackDispatcherMouse(GLFWwindow* window, double xpos, double ypos){
    WorldKeeper* world = static_cast<WorldKeeper*>(glfwGetWindowUserPointer(window));
        
    if (world) {
        world->getCamera()->getExtension<RotateCameraExtension>("RotateCameraExtension")->dirHandler(xpos, ypos);
    }
}

void RotateCameraExtension::dirHandler(double xpos, double ypos){
    GLfloat xoffset = xpos - this->lastX;
    GLfloat yoffset = this->lastY - ypos;
    this->lastX = xpos;
    this->lastY = ypos;

    xoffset *= this->sens;
    yoffset *= this->sens;     

    this->yaw += xoffset;
    this->pitch += yoffset;

    if(pitch > 89.0f)
        pitch =  89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
}

std::string RotateCameraExtension::getExName(){return "RotateCameraExtension";}

glm::mat4 RotateCameraExtension::getViewMatrix(){
    return this->viewMatrix;
}