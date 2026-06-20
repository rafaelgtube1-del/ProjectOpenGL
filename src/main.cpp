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

Window windowManager(width, height, title);
Interface interface;
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f);
Renderer renderer;

int main() {
    windowManager.create();
    interface.create(windowManager.getWindow());

    DefaultShader defaultShader;

    MeshData cube = Shapes::getCubeMesh();
    Transform transform;

    Mesh mesh(cube, false);
    Object object(transform, mesh);

    renderer.addObject(object);

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    
    while (!glfwWindowShouldClose(windowManager.getWindow()))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Input::update();

        windowManager.clear();
        interface.clear();
        defaultShader.use();

        camera.update(deltaTime);

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