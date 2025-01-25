#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colors;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(position, 1.0f);
    vertexColor = vec4(colors, 1.0f);
}
