#include "object.hpp"

Object::Object(glm::vec3 position, glm::quat rotation, glm::vec3 scale, Mesh& mesh)
{
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
    this->mesh = &mesh;
}

glm::mat4 Object::getModelMatrix() const
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, position);
    model *= glm::mat4_cast(rotation);
    model = glm::scale(model, scale);

    return model;
}