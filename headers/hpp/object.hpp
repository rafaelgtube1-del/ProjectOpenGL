#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include <mesh.hpp>

class Object
{
public:
    glm::vec3 position;
    glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    glm::vec3 scale;

    Mesh* mesh;

    Object(glm::vec3 position, glm::quat rotation, glm::vec3 scale, Mesh& mesh);

    glm::mat4 getModelMatrix() const;
    
};

#endif