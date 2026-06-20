#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <string>

#include <stb/stbi_image.h>
#include <shader.hpp>

class Texture
{
private:
    unsigned int id;

public:
    Texture(const std::vector<std::string>& paths, int width, int height);

    void bind();
    void uniform(int index, int programId);
    void unbind();
    void destroy();

    unsigned int getId() const;
    
};

#endif