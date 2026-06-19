#include "shapes.hpp"

MeshData Shapes::getCubeMesh()
{
    MeshData data;
    data.vertices.assign(std::begin(Cube::vertices), std::end(Cube::vertices));
    data.indices.assign(std::begin(Cube::indices), std::end(Cube::indices));
    data.colors.assign(std::begin(Cube::colors), std::end(Cube::colors));

    return data;
}