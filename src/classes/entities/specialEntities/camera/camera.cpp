#include<classes/entities/specialEntities/camera/camera.hpp>
#include<classes/extensions/positionExtension.hpp>
#include<assets.h>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

std::vector<Extension*> initCamerasExts(std::vector<Extension*> extensions, glm::vec3 position){
    //extensions.push_back(new Position(position));
    return extensions;
}

glm::vec3 rotateAngle(glm::vec3 originVector, float yaw, float pitch){
    glm::quat yawQuat = glm::angleAxis((float)glm::radians(-yaw), glm::vec3(0, 1, 0));
    glm::quat pitchQuat = glm::angleAxis((float)glm::radians(-pitch), glm::vec3(1, 0.f, 0.f));
    glm::quat totalRot = glm::normalize(yawQuat * pitchQuat);

    return glm::normalize(totalRot * originVector);
}

Camera::Camera(glm::vec3 position, float fov, float sens, Entity* linkedEntity, TriggerManager* triggerManager){
    this->linkedEntity = linkedEntity;
    this->setPosition = position;
    this->triggerManager = triggerManager;
    this->sens = sens;

    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);

    this->previewPositionMouse = {width/2.f, height/2.f};

    this->yaw = -180.f;
    this->pitch = 0.f;
    this->sens = 0.05;

    this->initialDirections = linkedEntity->getExtension<MoveMent>("MoveMentExtension")->getKeyMoves();

    this->viewMatrix = glm::lookAt(this->getPosition(), this->getPosition() + rotateAngle(glm::vec3{0,0,1}, this->yaw, this->pitch), glm::vec3(0,1,0));
}

glm::vec3 Camera::getPosition(){
    glm::vec3 entityPosition = this->linkedEntity->getExtension<Position>("PositionExtension")->getPosition();
    return this->setPosition + entityPosition;
}

glm::mat4 Camera::getProjectionMatrix(){
    return this->projectionMatrix;
}

glm::mat4 Camera::getViewMatrix(){
    PositionMouse mousePos = this->triggerManager->getMouseTrigger()->getPositionMouse();

    GLfloat xoffset = mousePos.x - this->previewPositionMouse.x;
    GLfloat yoffset = this->previewPositionMouse.y - mousePos.y;

    this->previewPositionMouse = mousePos;

    xoffset *= this->sens;
    yoffset *= this->sens;

    this->yaw += xoffset;
    this->pitch += yoffset;

    if(pitch > 89.0f)
        pitch =  89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;

    std::cout << "yaw: " << this->yaw << "pitch: " << this->pitch << std::endl;

    glm::vec3 direction = rotateAngle(glm::vec3{0,0,1}, this->yaw, this->pitch);

    printGLMVector(direction);

    std::vector<KeyMove> newKeyMoves = this->initialDirections;

    for(int i = 0;i != newKeyMoves.size();i++){
        newKeyMoves[i].direct.x *= -1;
        newKeyMoves[i].direct = rotateAngle(this->initialDirections[i].direct, this->yaw, this->pitch);

        std::cout << newKeyMoves[i].key << std::endl;
        printGLMVector(newKeyMoves[i].direct);
        printGLMVector(this->initialDirections[i].direct);
    }

    this->linkedEntity->getExtension<MoveMent>("MoveMentExtension")->setKeyMoves(newKeyMoves);
    
    glm::vec3 position = this->getPosition();
    this->viewMatrix = glm::lookAt(position, position + direction, glm::vec3(0.f, 1.f, 0.f));

    return viewMatrix;
}