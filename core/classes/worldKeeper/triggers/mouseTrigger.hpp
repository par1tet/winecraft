#pragma once

#include<vector>

struct PositionMouse
{
    double x,y;
};


class MouseTrigger {
private:
    PositionMouse positionMouse;

public:
    MouseTrigger();

    void handleMouse(double xpos, double ypos);

    PositionMouse getPositionMouse();
};