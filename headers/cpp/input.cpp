#include "input.hpp"

void Input::update()
{
    GLFWwindow* window = glfwGetCurrentContext();
    if (!window) { return; }

    glfwGetCursorPos(window, &xMousePos, &yMousePos);

    for (int i = 0; i <= GLFW_KEY_LAST; i++)
    {
        keys[i] = (glfwGetKey(window, i) == GLFW_PRESS);
    }
}

bool Input::getKey(int key)
{
    return keys[key];
}

void Input::getMousePos(float *xPos, float *yPos)
{
    if (xPos) *xPos = static_cast<float>(xMousePos);
    if (yPos) *yPos = static_cast<float>(yMousePos);
}