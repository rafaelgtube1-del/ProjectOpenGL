#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <mesh.hpp>

class Chunk
{
private:
    int xChunkPos, zChunkPos;
    unsigned int* blocks[16][32][16];

    Mesh* mesh;
    
public:
    Chunk(int xPos, int zPos);
    
};

#endif