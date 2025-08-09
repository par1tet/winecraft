#pragma once

#include<glm/gtc/matrix_transform.hpp>
#include<classes/entities/entity.hpp>
#include<classes/worldKeeper/triggers/triggerManager.hpp>
#include<classes/entities/specialEntities/specialEntity.hpp>

class Camera : public SpecialEntity{
private:
    glm::mat4 projectionMatrix;
    glm::vec3 setPosition;
    Entity* linkedEntity;
    TriggerManager* triggerManager;
    glm::mat4 viewMatrix;
    PositionMouse previewPositionMouse;
    double yaw, pitch;
    float sens;

public:
    Camera(glm::vec3 position, float fov, float sens, Entity* linkedEntity, TriggerManager* TriggerManager);

    glm::mat4 getProjectionMatrix();
    glm::vec3 getPosition();
    glm::mat4 getViewMatrix();
};