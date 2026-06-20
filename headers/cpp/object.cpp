#include "object.hpp"

Object::Object(Transform &transform, Mesh& mesh)
{
    this->transform = transform;
    this->mesh = &mesh;
}

void Object::setTransform(Transform &transform)
{
    this->transform = transform;
}

Transform Object::getTransform() const
{
    return transform;
}

glm::mat4 Object::getModelMatrix() const
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, transform.position);
    model *= glm::mat4_cast(transform.rotation);
    model = glm::scale(model, transform.scale);

    return model;
}