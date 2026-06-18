#include "vao.hpp"

VAO::VAO()
{
    glGenVertexArrays(1, &id);
}

void VAO::bind() const
{
    glBindVertexArray(id);
}

void VAO::unbind() const
{
    glBindVertexArray(0);
}

void VAO::destroy()
{
    if (id != 0)
    {
        glDeleteVertexArrays(1, &id);
        id = 0;
    }
}

void VAO::linkVBO(const VBO& vbo, int size, int index)
{
    this->bind();
    vbo.bind();

    glVertexAttribPointer(index, size, GL_FLOAT, false, 0, (void*)0);
    glEnableVertexAttribArray(index);

    vbo.unbind();
    this->unbind();
}

void VAO::linkEBO(const EBO& ebo)
{
    this->bind();
    ebo.bind();

    this->unbind();
    ebo.unbind();
}

unsigned int VAO::getId() const
{
    return id;
}