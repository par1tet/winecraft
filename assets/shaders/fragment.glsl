#version 330 core

in vec2 TexCoords;

out vec4 color;

uniform sampler2D ourTexture;
uniform vec4 colorCube;

void main() {
    color = texture(ourTexture, TexCoords) * colorCube;
}
