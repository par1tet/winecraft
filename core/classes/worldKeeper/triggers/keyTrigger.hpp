#pragma once

#include<vector>

class KeyTrigger {
private:
    bool keys[348] = {false};

public:
    KeyTrigger();

    void handleKey(int key, int scancode, int action, int mode);

    bool* getKeys();
};