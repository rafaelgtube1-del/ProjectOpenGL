#pragma once

#include <shader.hpp>

class DefaultShader
{
private:
    unsigned int programId = 0;
    unsigned int vertexShaderId = 0;
    unsigned int fragmentShaderId = 0;

public:
    DefaultShader();

    void use();
    void destroy();

    int getId();

};