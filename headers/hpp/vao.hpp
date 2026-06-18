#ifndef VAO_HPP
#define VAO_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "vbo.hpp"
#include "ebo.hpp"

class VAO
{
private:
    unsigned int id = 0;
    
public:
    VAO();

    void bind() const;
    void unbind() const;
    void destroy();

    void linkVBO(const VBO& vbo, int size, int index);
    void linkEBO(const EBO& ebo);

    unsigned int getId() const;
    
};

#endif