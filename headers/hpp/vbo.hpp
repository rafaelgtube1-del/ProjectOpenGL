#ifndef VBO_HPP
#define VBO_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class VBO
{
private:
    unsigned int id = 0;

public:
    VBO(const void* data, unsigned int size);

    void bind() const;
    void unbind() const;
    void destroy();

    unsigned int getId() const;
    
};

#endif