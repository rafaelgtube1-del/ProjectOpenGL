#include "ebo.hpp"

EBO::EBO(const void* data, unsigned int size)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

void EBO::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::destroy()
{
    if (id != 0)
    {
        glDeleteBuffers(1, &id);
        id = 0;
    }
}

unsigned int EBO::getId() const
{
    return id;
}