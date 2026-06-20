#version 330 core

in vec3 bTexCoords;

out vec4 FragColor;

uniform sampler2DArray textureArray;

void main()
{
    FragColor = texture(textureArray, bTexCoords);
}