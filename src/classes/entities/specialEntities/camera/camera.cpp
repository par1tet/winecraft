#include<classes/entities/specialEntities/camera/camera.hpp>
#include<classes/extensions/positionExtension.hpp>

std::vector<Extension*> initCamerasExts(std::vector<Extension*> extensions, glm::vec3 position){
    //extensions.push_back(new Position(position));
    return extensions;
}


Camera::Camera(glm::vec3 position, float fov, float sens, Entity* linkedEntity, TriggerManager* triggerManager){
    this->linkedEntity = linkedEntity;
    this->setPosition = position;
    this->triggerManager = triggerManager;
    this->sens = sens;

    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);

    this->previewPositionMouse = {width/2.f, height/2.f};

    this->yaw = -90.f;
    this->pitch = 0.f;
    this->sens = 0.05;

    glm::vec3 front;

    front.x = cos(glm::radians(this->pitch)) * cos(glm::radians(this->yaw));
    front.y = sin(glm::radians(this->pitch));
    front.z = cos(glm::radians(this->pitch)) * sin(glm::radians(this->yaw));

    glm::vec3 direction = glm::normalize(front);
    this->viewMatrix = glm::lookAt(this->getPosition(), this->getPosition() + direction, glm::vec3(0,1,0));
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

    std::cout << "yaw: " << this->yaw << "pitch: " << this->pitch << std::endl;

    glm::vec3 front;
    front.x = cos(glm::radians(this->pitch)) * cos(glm::radians(this->yaw));
    front.y = sin(glm::radians(this->pitch));
    front.z = cos(glm::radians(this->pitch)) * sin(glm::radians(this->yaw));
    glm::vec3 direction = glm::normalize(front);

    glm::vec3 position = this->getPosition();
    this->viewMatrix = glm::lookAt(position, position + direction, glm::vec3(0.f, 1.f, 0.f));

    return viewMatrix;
}