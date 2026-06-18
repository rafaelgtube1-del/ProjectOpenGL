#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
    int width = 900;
    int height = 600;
    std::string title = "Mirox";

    GLFWwindow* window = nullptr;

public:
    Window(int width, int height, std::string title);

    int create();
    void clear();
    void update();
    void destroy();

    GLFWwindow* getWindow() const;
    
};