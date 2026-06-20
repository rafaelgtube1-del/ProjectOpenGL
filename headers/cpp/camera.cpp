#include "camera.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;

    updateVectors();
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return glm::perspective(glm::radians(fovy), width / height, 0.1f, 100.0f);
}

void Camera::processMoviment(glm::vec3 direction, float deltaTime)
{
    float velocity = speed * deltaTime;
    
    if (direction == glm::vec3(0.0f, 0.0f, -1.0f))
    { position += front * velocity; }
    if (direction == glm::vec3(0.0f, 0.0f, 1.0f))
    { position -= front * velocity; }
    if (direction == glm::vec3(-1.0f, 0.0f, 0.0f))
    { position -= right * velocity; }
    if (direction == glm::vec3(1.0f, 0.0f, 0.0f))
    { position += right * velocity; }

    if (direction == glm::vec3(0.0f, 1.0f, 0.0f))
    { position += up * velocity; }
    if (direction == glm::vec3(0.0f, -1.0f, 0.0f))
    { position -= up * velocity; }
}

void Camera::processRotate(float xOffset, float yOffset)
{
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f) { pitch = 89.0f; }
    if (pitch < -89.0f) { pitch = -89.0f; }

    updateVectors();
}

void Camera::updateMouse()
{
    if (!mouseLocked) { return; }

    float xPos, yPos;
    Input::getMousePos(&xPos, &yPos);

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

    processRotate(xOffset, yOffset);
}

void Camera::update(float deltaTime)
{
    if (Input::getKey(GLFW_KEY_W))
    { processMoviment(glm::vec3(0.0f, 0.0f, -1.0f), deltaTime); }
    if (Input::getKey(GLFW_KEY_S))
    { processMoviment(glm::vec3(0.0f, 0.0f, 1.0f), deltaTime); }
    if (Input::getKey(GLFW_KEY_A))
    { processMoviment(glm::vec3(-1.0f, 0.0f, 0.0f), deltaTime); }
    if (Input::getKey(GLFW_KEY_D))
    { processMoviment(glm::vec3(1.0f, 0.0f, 0.0f), deltaTime); }

    if (Input::getKey(GLFW_KEY_E))
    { processMoviment(glm::vec3(0.0f, 1.0f, 0.0f), deltaTime); }
    if (Input::getKey(GLFW_KEY_Q))
    { processMoviment(glm::vec3(0.0f, -1.0f, 0.0f), deltaTime); }

    if (Input::getKey(GLFW_KEY_LEFT_SHIFT))
    {
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        mouseLocked = false;
    }
    if (Input::getKey(GLFW_KEY_LEFT_CONTROL))
    {
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        mouseLocked = true;
        firstMouse = true;
    }

    updateMouse();
}

void Camera::setScreenSize(float width, float height)
{
    this->width = width;
    this->height = height;
}

void Camera::updateVectors()
{
    glm::vec3 newFront;

    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    front = glm::normalize(newFront);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}