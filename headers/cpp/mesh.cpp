#include "mesh.hpp"

Mesh::Mesh(const MeshData &data, bool transparent)
    : verticeVBO(data.vertices.data(), data.vertices.size() * sizeof(float)),
    texCoordVBO(data.texCoords.data(), data.texCoords.size() * sizeof(float)),
    layerIdVBO(data.layerIds.data(), data.layerIds.size() * sizeof(unsigned int)),
    indiceEBO(data.indices.data(), data.indices.size() * sizeof(unsigned int)),
    transparent(transparent),
    indexCount(data.indices.size())
{
    vao.linkVBO(verticeVBO, 3, 0);
    vao.linkVBO(texCoordVBO, 2, 1);
    vao.linkVBO(layerIdVBO, 1, 2);
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
    texCoordVBO.destroy();
    layerIdVBO.destroy();
    indiceEBO.destroy();
}