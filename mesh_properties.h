#pragma once
#include <glm/glm.hpp>

#include <vector>

#include "object_property.h"

using namespace std;

struct Vertex {
    glm::vec2 pos;
    glm::vec3 color;
};

class MeshProperties : ObjectProperty{
public:
    MeshProperties() {
        
    }

private:
    const std::vector<Vertex> vertices = {
    {{0.5f, -0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, //Top left
    {{-0.5f, -0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}}, //Top right
    {{0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}, //Bottom left
    {{-0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},//Bottom right

    {{0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}}, //Top left
    {{-0.5f, -0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, //Top right
    {{0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {1.0f, 1.0f}},  //Bottom left
    {{-0.5f, 0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}},//Bottom right
    };

    const std::vector<uint16_t> indices = {
        2, 1, 0, 1, 2, 3, //Top
        4, 5, 6, 7, 6, 5, //Bottom
        4, 2, 0, 2, 4, 6, //Left
        1, 3, 5, 7, 5, 3, //Right
        6, 3, 2, 3, 6, 7, //Front
        0, 1, 4, 5, 4, 1, //Back
    };
};