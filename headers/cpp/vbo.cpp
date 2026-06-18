#include "vbo.hpp"

VBO::VBO(const void* data, unsigned int size)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::destroy()
{
    if (id != 0)
    {
        glDeleteBuffers(1, &id);
        id = 0;
    }
}

unsigned int VBO::getId() const
{
    return id;
}