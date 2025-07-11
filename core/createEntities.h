#pragma once

#include <vector>
#include <classes/objects/object.hpp>
#include <classes/entities/entity.hpp>
#include <string>

std::vector<Object*> createCubeObjects(std::vector<glm::vec3> positions, std::vector<glm::vec3> sizes);
std::vector<Object*> createCubeObjects(std::vector<glm::vec3> positions, std::vector<glm::vec3> sizes, std::vector<std::string> textures);
Entity* createCube(glm::vec3 position, glm::vec3 size, std::string texturePath);
Entity* createCube(glm::vec3 position, glm::vec3 size);
Entity* createCube(glm::vec3 position);
Entity* createCube(glm::vec3 position, std::string texturePath);