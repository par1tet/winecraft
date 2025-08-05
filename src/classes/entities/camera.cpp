#include<classes/entities/camera.hpp>

std::vector<Extension*> addPositionExt(std::vector<Extension*>& extensions, glm::vec3 position){
    extensions.push_back(new Position(position));
    return extensions;
}

Camera::Camera(glm::vec3 position, float fov, std::vector<Extension*> extensions) : Entity(addPositionExt(extensions, position)) {
    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);

}

Camera::Camera(glm::vec3 position, float fov) : Entity(std::vector<Extension*>{new Position(position)}){
    this->projectionMatrix = glm::mat4(1.0f);
    projectionMatrix = glm::perspective(glm::radians(fov), float(width/height), 0.1f, 100.0f);
}

glm::vec3 Camera::getPosition(){
 return this->getExtension<Position>("PositionExtension")->getPosition();
}

glm::mat4 Camera::getProjectionMatrix(){
    return this->projectionMatrix;
}