#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::vec3(-1.0f, 0.0f, 0.0f);
    glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float yaw = -90.0f;
    float pitch = 0.0f;

    float speed = 2.5f;
    float sensitivity = 0.1f;
    float fovy = 45.0f;

    float width = 900;
    float height = 600;

    void updateVectors();

public:
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;

    void processMoviment(glm::vec3 direction, float deltaTime);
    void processRotate(float xOffset, float yOffset);

    void setScreenSize(float width, float height);
    
};