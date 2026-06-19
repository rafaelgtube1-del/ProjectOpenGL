#pragma once

#include <iostream>
#include <array>

#include <mesh.hpp>

namespace Cube {
    inline constexpr std::array<float, 24> vertices = {
        0.0f, 0.0f, 0.0f,  1.0f, 0.0f, 0.0f, // 0, 1
        1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f, // 2, 3

        0.0f, 0.0f, 1.0f,  1.0f, 0.0f, 1.0f, // 4, 5
        1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f, // 6, 7
    };

    inline constexpr std::array<unsigned int, 36> indices = {
        0, 1, 2,  0, 2, 3, // front
        4, 7, 6,  4, 6, 5, // back
        0, 3, 7,  0, 7, 4, // left
        5, 6, 2,  5, 2, 1, // right
        7, 3, 2,  7, 2, 6, // top
        0, 4, 5,  0, 5, 1, // bottom
    };

    inline constexpr std::array<float, 24> colors = {
        1.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
    };
}

class Shapes
{
public:
    static MeshData getCubeMesh();
    
};