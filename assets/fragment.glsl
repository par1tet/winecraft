#version 330 core

in vec4 vertexColor;  
out vec4 color;

uniform float time;  

void main()
{
    float angle = time * 2.5f;  // для регулирования скорость вращения

    float r = 0.5f + 0.5f * sin(angle);  
    float g = 0.5f + 0.5f * sin(angle + 2.0f * 3.14159f / 3.0f);  
    float b = 0.5f + 0.5f * sin(angle + 4.0f * 3.14159f / 3.0f);  


    vec3 animatedColor = vec3(
        vertexColor.r * r,
        vertexColor.g * g,
        vertexColor.b * b
    );

    color = vec4(animatedColor, 1.0f);
}
