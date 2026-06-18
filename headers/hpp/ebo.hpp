#ifndef EBO_HPP
#define EBO_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class EBO
{
private:
    unsigned int id = 0;

public:
    EBO(const void* data, unsigned int size);

    void bind() const;
    void unbind() const;
    void destroy();

    unsigned int getId() const;
    
};

#endif