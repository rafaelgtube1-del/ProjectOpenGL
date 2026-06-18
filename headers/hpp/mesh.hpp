#ifndef MESH_HPP
#define MESH_HPP

#include <glad/glad.h>
#include <iostream>
#include <vector>

#include <vao.hpp>
#include <vbo.hpp>
#include <ebo.hpp>

class Mesh
{
private:
    VAO vao;
    VBO verticeVBO;
    VBO colorVBO;
    EBO indiceEBO;

    unsigned int indexCount = 0;

public:
    bool transparent = false;
    
    Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, const std::vector<float> &colors, bool transparent);

    void draw();
    void destroy();
    
};

#endif