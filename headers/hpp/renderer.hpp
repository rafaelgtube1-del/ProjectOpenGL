#pragma once

#include <iostream>
#include <vector>

#include <camera.hpp>
#include <shader.hpp>
#include <defaultShader.hpp>
#include <object.hpp>

class Renderer
{
private:
    std::vector<Object> objects;
    
public:
    void addObject(const Object& object);
    void removeObject(unsigned int index);

    void render(DefaultShader& defaultShader, Camera& camera);

    void destroy();

};