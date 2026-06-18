#include "shader.hpp"

std::string Shader::readFile(std::string name)
{
    std::string path = std::string("resource/shader/") + name;
    std::ifstream file;
    
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        file.open(path);

        std::stringstream buffer;
        buffer << file.rdbuf();

        file.close();

        return buffer.str();
    }
    catch(std::ifstream::failure& e)
    {
        std::cerr << e.what() << '\n';
        return "";
    }
}

int Shader::createShader(GLenum type, std::string name)
{
    std::string shaderCode = readFile(name);
    if (shaderCode.empty()) { return 0; }
    
    unsigned int shaderId;
    shaderId = glCreateShader(type);

    const char* shaderSource = shaderCode.c_str();
    glShaderSource(shaderId, 1, &shaderSource, NULL);

    glCompileShader(shaderId);
    return shaderId;
}

void Shader::destroyShader(int shaderId)
{
    glDeleteShader(shaderId);
}

int Shader::createProgram(int vertexShader, int fragmentShader)
{
    unsigned int programId;
    programId = glCreateProgram();

    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);

    glLinkProgram(programId);
    return programId;
}

void Shader::useProgram(int programId)
{
    glUseProgram(programId);
}

void Shader::destroyProgram(int programId)
{
    glDeleteProgram(programId);
}

int Shader::getUniformLocation(int programId, std::string name)
{
    return glGetUniformLocation(programId, name.c_str());
}

void Shader::setUniformInt(int programId, std::string name, int value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniform1i(uniformLocation, value);
    }
}

void Shader::setUniformFloat(int programId, std::string name, float value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniform1f(uniformLocation, value);
    }
}

void Shader::setUniformVec2(int programId, std::string name, glm::vec2 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniform2f(uniformLocation, value.x, value.y);
    }
}

void Shader::setUniformVec3(int programId, std::string name, glm::vec3 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniform3f(uniformLocation, value.x, value.y, value.z);
    }
}

void Shader::setUniformVec4(int programId, std::string name, glm::vec4 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniform4f(uniformLocation, value.x, value.y, value.z, value.w);
    }
}

void Shader::setUniformMat2(int programId, std::string name, glm::mat2 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniformMatrix2fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
}

void Shader::setUniformMat3(int programId, std::string name, glm::mat3 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
}

void Shader::setUniformMat4(int programId, std::string name, glm::mat4 value)
{
    int uniformLocation = getUniformLocation(programId, name);
    if (uniformLocation != -1)
    {
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
    }
}
