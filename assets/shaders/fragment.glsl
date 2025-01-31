#version 330 core

in vec2 TexCoords;
in mat4 outTransform;

out vec4 color;

uniform sampler2D ourTexture;
uniform vec4 colorCube;

void main() {
    color = texture(ourTexture, TexCoords) * colorCube;
}
