#ifndef MESH_HPP
#define MESH_HPP

#include <glad/glad.h>
#include <iostream>
#include <vector>

#include <vao.hpp>
#include <vbo.hpp>
#include <ebo.hpp>

struct MeshData
{
    std::vector<float> vertices = {};
    std::vector<unsigned int> indices = {};
    std::vector<float> colors = {};
};

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
    
    Mesh(const MeshData &data, bool transparent);

    void draw();
    void destroy();
    
};

#endif