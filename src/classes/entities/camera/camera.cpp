#include<classes/entities/camera/camera.hpp>

std::vector<Extension*> initCamerasExts(std::vector<Extension*> extensions, glm::vec3 position){
    //extensions.push_back(new Position(position));
    return extensions;
}

Camera::Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions, float sens, GLFWwindow* window) : Entity(initCamerasExts(extensions, position)) {
    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);
}

Camera::Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions, GLFWwindow* window) : Entity(initCamerasExts(extensions, position)) {
    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);
}

Camera::Camera(glm::vec3 position, float fov, GLFWwindow* window) : Entity(initCamerasExts((std::vector<Extension*>()), position)){
    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);
}

glm::vec3 Camera::getPosition(){
    //return this->getExtension<Position>("PositionExtension")->getPosition();
    return glm::vec3{0.f};
}

glm::mat4 Camera::getProjectionMatrix(){
    return this->projectionMatrix;
}
