#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 TexCoords;
out mat4 outTransform;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec3 sizeCube;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4((position * sizeCube), 1.0f);
    TexCoords = texCoord;
}
