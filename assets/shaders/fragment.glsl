#version 330 core

in vec2 TexCoords;
in mat4 outTransform;

out vec4 color;

uniform sampler2D ourTexture;

void main() {
    color = texture(ourTexture, TexCoords);
}
