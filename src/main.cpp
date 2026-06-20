#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
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
#include <texture.hpp>

#include <mesh.hpp>
#include <object.hpp>
#include <renderer.hpp>
#include <shapes.hpp>

int width = 900;
int height = 600;
std::string title = "Mirox";

std::vector<std::string> texturePaths = {
    "resource/texture/grass.png",
    "resource/texture/dirt.png",
    "resource/texture/stone.png",
};

Window windowManager(width, height, title);
Interface interface;
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), 0.0f, 0.0f);
Renderer renderer;

int main() {
    windowManager.create();
    interface.create(windowManager.getWindow());

    Texture texture(texturePaths, 8, 8);
    DefaultShader defaultShader;

    for (int x = 0; x < 16; x++)
    {
        for (int z = 0; z < 16; z++)
        {
            for (int y = 0; y <= 6; y++)
            {
                MeshData cube = Shapes::getCubeMesh(1);
                Transform transform;
                transform.position = glm::vec3(x, y, z);

                Mesh mesh(cube, false);
                Object object(transform, mesh);

                renderer.addObject(object);
            }
        }
    }

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    
    while (!glfwWindowShouldClose(windowManager.getWindow()))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        windowManager.clear();
        interface.clear();
        defaultShader.use();
        texture.uniform(0, defaultShader.getId());

        Input::update();
        camera.update(deltaTime);

        renderer.render(defaultShader, camera);

        interface.update();
        windowManager.update();
    }

    windowManager.destroy();
    interface.destroy();
    defaultShader.destroy();
    texture.destroy();
    renderer.destroy();

    return 0;
}