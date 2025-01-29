#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colors;
layout (location = 2) in vec2 textureCoordinates;

out vec4 vertexColor;
out vec2 texCoords;

void main()
{
    gl_Position = vec4(position, 1.0f);
    vertexColor = vec4(colors, 1.0f);
    texCoords = textureCoordinates;
}