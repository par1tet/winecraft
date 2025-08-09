#pragma once

#include<glm/gtc/matrix_transform.hpp>
#include<classes/entities/entity.hpp>

class Camera : public Entity {
private:
    glm::mat4 projectionMatrix;

public:
    Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions, float sens, GLFWwindow* window);
    Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions, GLFWwindow* window);
    Camera(glm::vec3 position, float fov, GLFWwindow* window);
    Camera(glm::vec3 position, float fov, float sens, GLFWwindow* window);

    glm::mat4 getProjectionMatrix();
    glm::vec3 getPosition();
};