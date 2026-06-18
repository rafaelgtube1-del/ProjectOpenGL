#pragma once

#include <GLFW/glfw3.h>

class Input
{
private:
    inline static bool keys[GLFW_KEY_LAST + 1] = {};

public:
    Input() = delete;

    static void update();
    static bool getKey(int key);

};
