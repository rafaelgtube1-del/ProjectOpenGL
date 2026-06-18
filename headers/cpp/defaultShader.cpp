#include "defaultShader.hpp"

DefaultShader::DefaultShader()
{
    vertexShaderId = Shader::createShader(GL_VERTEX_SHADER, "default.vert");
    fragmentShaderId = Shader::createShader(GL_FRAGMENT_SHADER, "default.frag");

    programId = Shader::createProgram(vertexShaderId, fragmentShaderId);

    Shader::destroyShader(vertexShaderId);
    Shader::destroyShader(fragmentShaderId);
}

void DefaultShader::use()
{
    Shader::useProgram(programId);
}

void DefaultShader::destroy()
{
    Shader::destroyProgram(programId);
}

int DefaultShader::getId()
{
    return programId;
}