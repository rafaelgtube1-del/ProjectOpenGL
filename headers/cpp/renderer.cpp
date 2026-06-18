#include "renderer.hpp"

void Renderer::addObject(const Object& object)
{
    objects.push_back(object);
}

void Renderer::removeObject(unsigned int index)
{
    if (index < objects.size()) {
        objects.erase(objects.begin() + index);
    }
}

void Renderer::render(DefaultShader& defaultShader, Camera& camera)
{
    unsigned int id = defaultShader.getId();

    Shader::setUniformMat4(id, "projection", camera.getProjectionMatrix());
    Shader::setUniformMat4(id, "view", camera.getViewMatrix());

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);

    for (Object object : objects)
    {
        if (object.mesh->transparent) { continue; }

        Shader::setUniformMat4(id, "model", object.getModelMatrix());
        object.mesh->draw();
    }

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);

    for (Object object : objects)
    {
        if (!object.mesh->transparent) { continue; }
        
        Shader::setUniformMat4(id, "model", object.getModelMatrix());
        object.mesh->draw();
    }

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

void Renderer::destroy()
{
    for (Object object : objects)
    {
        object.mesh->destroy();
    }

    objects.clear();
}