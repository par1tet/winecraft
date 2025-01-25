#version 330 core

in vec4 vertexColor;  // Входящий цвет от вершинного шейдера
out vec4 color;

uniform float time;  // Время для анимации (передается из C++)

void main()
{
    // Рассчитываем угол для анимации, который будет изменяться с течением времени
    float angle = time * 2.0f;  // Регулируйте скорость вращения

    // Вычисляем циклические сдвиги для каждой компоненты
    float r = 0.5f + 0.5f * sin(angle);  // Плавное изменение компоненты R
    float g = 0.5f + 0.5f * sin(angle + 2.0f * 3.14159f / 3.0f);  // Плавное изменение компоненты G
    float b = 0.5f + 0.5f * sin(angle + 4.0f * 3.14159f / 3.0f);  // Плавное изменение компоненты B


    // Смешиваем начальный градиент с анимированными значениями
    vec3 animatedColor = vec3(
        vertexColor.r * r,
        vertexColor.g * g,
        vertexColor.b * b
    );

    // Выводим анимированный цвет
    color = vec4(animatedColor, 1.0f);
}
