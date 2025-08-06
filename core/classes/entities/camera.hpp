#pragma once

#include<classes/entities/entity.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<classes/extensions/positionExtension.hpp>
#include<classes/extensions/moveMentExtension.hpp>

class Camera : public Entity {
private:
    glm::mat4 projectionMatrix;

public:
    Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions);
    Camera(glm::vec3 position, float fov);

    glm::mat4 getProjectionMatrix();
    glm::vec3 getPosition();
};