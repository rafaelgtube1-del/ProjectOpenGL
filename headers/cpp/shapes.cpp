#include "shapes.hpp"

MeshData Shapes::getCubeMesh(int id)
{
    MeshData data;
    data.vertices.assign(std::begin(Cube::vertices), std::end(Cube::vertices));
    data.indices.assign(std::begin(Cube::indices), std::end(Cube::indices));
    data.texCoords.assign(std::begin(Cube::texCoords), std::end(Cube::texCoords));
    data.layerIds.assign(std::begin(Cube::layerIds), std::end(Cube::layerIds));

    for (int i = 0; i < data.layerIds.size(); i++)
    {
        data.layerIds[i] = id;
    }

    return data;
}