#include "texture.hpp"

Texture::Texture(const std::vector<std::string>& paths, int width, int height)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D_ARRAY, id);

    int depth = static_cast<int>(paths.size());

    glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, width, height, depth, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

    stbi_set_flip_vertically_on_load(true);

    for (int i = 0; i < depth; i++)
    {
        int iWidth, iHeight, iChannels;

        unsigned char* data = stbi_load(paths[i].c_str(), &iWidth, &iHeight, &iChannels, 4);

        if (data)
        {
            if (iWidth != width || iHeight != height)
            {
                stbi_image_free(data);
                continue;
            }

            glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, width, height, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
    }

    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, id);
}

void Texture::uniform(int index, int programId)
{
    glActiveTexture(GL_TEXTURE0 + index);
    bind();
    Shader::setUniformInt(programId, "textureArray", index);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
}

void Texture::destroy()
{
    glDeleteTextures(1, &id);
}

unsigned int Texture::getId() const
{
    return id;
}