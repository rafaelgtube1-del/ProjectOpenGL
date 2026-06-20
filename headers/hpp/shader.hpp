#define GLFW_INCLUDE_NONE

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <format>

class Shader
{
private:
    static std::string readFile(std::string name);

public:
    Shader() = delete;

    static int createShader(GLenum type, std::string name);
    static void destroyShader(int shaderId);

    static int createProgram(int vertexShader, int fragmentShader);
    static void useProgram(int programId);
    static void destroyProgram(int programId);

    static int getUniformLocation(int programId, std::string name);

    static void setUniformInt(int programId, std::string name, int value);
    static void setUniformFloat(int programId, std::string name, float value);

    static void setUniformVec2(int programId, std::string name, glm::vec2 value);
    static void setUniformVec3(int programId, std::string name, glm::vec3 value);
    static void setUniformVec4(int programId, std::string name, glm::vec4 value);

    static void setUniformMat2(int programId, std::string name, glm::mat2 value);
    static void setUniformMat3(int programId, std::string name, glm::mat3 value);
    static void setUniformMat4(int programId, std::string name, glm::mat4 value);

};