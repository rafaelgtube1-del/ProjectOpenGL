#include "mesh.hpp"

Mesh::Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, const std::vector<float> &colors, bool transparent)
    : verticeVBO(vertices.data(), vertices.size() * sizeof(float)),
    colorVBO(colors.data(), colors.size() * sizeof(float)),
    indiceEBO(indices.data(), indices.size() * sizeof(unsigned int)),
    transparent(transparent),
    indexCount(indices.size())
{
    vao.linkVBO(verticeVBO, 3, 0);
    vao.linkVBO(colorVBO, 4, 1);
    vao.linkEBO(indiceEBO);
}

void Mesh::draw()
{
    vao.bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    vao.unbind();
}

void Mesh::destroy()
{
    vao.destroy();
    verticeVBO.destroy();
    colorVBO.destroy();
    indiceEBO.destroy();
}