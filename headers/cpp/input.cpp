#include "input.hpp"

void Input::update()
{
    GLFWwindow* window = glfwGetCurrentContext();
    if (!window) { return; }

    for (int i = 0; i <= GLFW_KEY_LAST; i++)
    {
        keys[i] = (glfwGetKey(window, i) == GLFW_PRESS);
    }
}

bool Input::getKey(int key)
{
    return keys[key];
}