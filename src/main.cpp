#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <vector>

#include <window.hpp>
#include <camera.hpp>
#include <input.hpp>
#include <interface.hpp>

#include <vao.hpp>
#include <vbo.hpp>
#include <ebo.hpp>

#include <defaultShader.hpp>

#include <mesh.hpp>
#include <object.hpp>
#include <renderer.hpp>
#include <shapes.hpp>

int width = 900;
int height = 600;
std::string title = "Mirox";

float lastMouseX = width / 2.0f;
float lastMouseY = height / 2.0f;
bool firstMouse = true;
bool mouseLocked = false;

Window windowManager(width, height, title);
Interface interface;
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f);

DefaultShader defaultShader;
Renderer renderer;

int main() {
    windowManager.create();
    interface.create(windowManager.getWindow());

    MeshData cube = Shapes::getCubeMesh();
    Transform transform;

    Mesh mesh(cube, false);
    Object object(transform, mesh);

    renderer.addObject(object);

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    glfwSetCursorPosCallback(windowManager.getWindow(), [](GLFWwindow* win, double xPosD, double yPosD) {
        if (!mouseLocked) { return; }

        float xPos = static_cast<float>(xPosD);
        float yPos = static_cast<float>(yPosD);

        if (firstMouse)
        {
            lastMouseX = xPos;
            lastMouseY = yPos;
            firstMouse = false;
        }

        float xOffset = xPos - lastMouseX;
        float yOffset = lastMouseY - yPos;

        lastMouseX = xPos;
        lastMouseY = yPos;

        camera.processRotate(xOffset, yOffset);
    });

    glfwSetKeyCallback(windowManager.getWindow(), [](GLFWwindow* win, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS)
        {
            mouseLocked = !mouseLocked;
            if (mouseLocked) { firstMouse = true; }

            glfwSetInputMode(windowManager.getWindow(), GLFW_CURSOR, mouseLocked ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
        }
    });
    
    while (!glfwWindowShouldClose(windowManager.getWindow()))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Input::update();

        windowManager.clear();
        interface.clear();
        defaultShader.use();

        if (Input::getKey(GLFW_KEY_W))
        { camera.processMoviment(glm::vec3(0.0f, 0.0f, -1.0f), deltaTime); }
        if (Input::getKey(GLFW_KEY_S))
        { camera.processMoviment(glm::vec3(0.0f, 0.0f, 1.0f), deltaTime); }
        if (Input::getKey(GLFW_KEY_A))
        { camera.processMoviment(glm::vec3(-1.0f, 0.0f, 0.0f), deltaTime); }
        if (Input::getKey(GLFW_KEY_D))
        { camera.processMoviment(glm::vec3(1.0f, 0.0f, 0.0f), deltaTime); }

        if (Input::getKey(GLFW_KEY_E))
        { camera.processMoviment(glm::vec3(0.0f, 1.0f, 0.0f), deltaTime); }
        if (Input::getKey(GLFW_KEY_Q))
        { camera.processMoviment(glm::vec3(0.0f, -1.0f, 0.0f), deltaTime); }

        renderer.render(defaultShader, camera);

        interface.update();
        windowManager.update();
    }

    windowManager.destroy();
    interface.destroy();
    defaultShader.destroy();
    renderer.destroy();

    return 0;
}