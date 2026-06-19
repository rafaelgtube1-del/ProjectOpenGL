#pragma once

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Interface
{
private:
    void run();
    
public:
    void create(const GLFWwindow* window);
    void clear();
    void update();
    void destroy();
    
};