#pragma once

#include <iostream>
#include <array>

#include <mesh.hpp>

namespace Cube {
    inline constexpr std::array<float, 72> vertices = {
        // front
        0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
        // back
        0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, 1.0f,
        // left
        0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f,
        // right
        1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f, 1.0f,
        // top
        0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,
        // bottom
        0.0f, 0.0f, 1.0f,  1.0f, 0.0f, 1.0f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f, 0.0f
    };

    inline constexpr std::array<unsigned int, 36> indices = {
        0,  2,  1,   0,  3,  2,  // front
        4,  6,  5,   4,  7,  6,  // back
        8,  9, 10,   8,  10, 11, // left
        12, 13, 14,  12, 14, 15, // right
        16, 18, 17,  16, 19, 18, // top
        20, 22, 21,  20, 23, 22  // bottom
    };

    inline constexpr std::array<float, 48> texCoords = {
        // front (Vértices caminham na ordem: inf-esq, inf-dir, sup-dir, sup-esq)
        0.0f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f,  1.0f, 0.0f,

        // back (Vértices caminham na ordem: inf-esq, sup-esq, sup-dir, inf-dir)
        0.0f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f,  1.0f, 0.0f,

        // left (Vértices caminham na ordem: inf-dir, sup-dir, sup-esq, inf-esq)
        1.0f, 0.0f,  1.0f, 1.0f,  0.0f, 1.0f,  0.0f, 0.0f,

        // right (Vértices caminham na ordem: inf-esq, sup-esq, sup-dir, inf-dir)
        0.0f, 0.0f,  0.0f, 1.0f,  1.0f, 1.0f,  1.0f, 0.0f,

        // top (Vértices caminham na ordem: inf-esq, inf-dir, sup-dir, sup-esq)
        0.0f, 1.0f,  1.0f, 1.0f,  1.0f, 0.0f,  0.0f, 0.0f,

        // bottom (Vértices caminham na ordem: sup-esq, sup-dir, inf-dir, inf-esq)
        0.0f, 1.0f,  1.0f, 1.0f,  1.0f, 0.0f,  0.0f, 0.0f
    };

    inline constexpr std::array<float, 24> layerIds = {
        0.0f, 0.0f, 0.0f, 0.0f, // front
        0.0f, 0.0f, 0.0f, 0.0f, // back
        0.0f, 0.0f, 0.0f, 0.0f, // left
        0.0f, 0.0f, 0.0f, 0.0f, // right
        0.0f, 0.0f, 0.0f, 0.0f, // top
        0.0f, 0.0f, 0.0f, 0.0f  // bottom
    };
}

class Shapes
{
public:
    static MeshData getCubeMesh(int id);
    
};