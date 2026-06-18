#include "window.hpp"

Window::Window(int width, int height, std::string title)
{
    if (!glfwInit()) { return; }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->width = width;
    this->height = height;
    this->title = title;
}

int Window::create()
{
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == nullptr) { return -1; }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Glad error!" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}

void Window::clear()
{
    glClearColor(0.7f, 0.7f, 0.7f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::destroy()
{
    glfwDestroyWindow(window);
    glfwTerminate();

    window = nullptr;
}

GLFWwindow* Window::getWindow() const
{
    return window;
}