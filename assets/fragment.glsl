#version 330 core
in vec4 vertexColor;

out vec4 color;

uniform vec3 greenColor;

void main()
{
    color = vec4(vertexColor.xyz,  1.0f);
}

