#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <classes/entities/entity.hpp>
#include <vector>

using namespace std;

extern int width, height;

extern int targetFps;
extern float sizeCube;

extern float dt;

extern GLfloat vertices[24], texCoords[16];
extern GLuint indeces[36];