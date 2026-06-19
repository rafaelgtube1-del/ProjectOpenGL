#include "mesh.hpp"

Mesh::Mesh(const MeshData &data, bool transparent)
    : verticeVBO(data.vertices.data(), data.vertices.size() * sizeof(float)),
    colorVBO(data.colors.data(), data.colors.size() * sizeof(float)),
    indiceEBO(data.indices.data(), data.indices.size() * sizeof(unsigned int)),
    transparent(transparent),
    indexCount(data.indices.size())
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