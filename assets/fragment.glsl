#version 330 core

in vec4 vertexColor;

out vec4 color;

uniform float phaseValue;
uniform int numberPhase;

void main()
{
    vec3 animatedColor = vec3(vertexColor.xyz);

    float tempZero = animatedColor[0];

    if(numberPhase == 3){
        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;
    }

    if(numberPhase == 2){
        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;

        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;
    }

    if(numberPhase == 3){
        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;

        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;

        tempZero = animatedColor[0];
        animatedColor[0] = animatedColor[1];
        animatedColor[1] = animatedColor[2];
        animatedColor[2] = tempZero;
    }
    tempZero = animatedColor[0];

    animatedColor[0] += (animatedColor[1] - animatedColor[0]) * phaseValue;
    animatedColor[1] += (animatedColor[2] - animatedColor[1]) * phaseValue;
    animatedColor[2] += (tempZero - animatedColor[2]) * phaseValue;

    color = vec4(animatedColor.x, animatedColor.y, animatedColor.z,  1.0f);
}