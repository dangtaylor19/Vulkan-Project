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
    const vector<Vertex> vertices = {
        {{-0.5f, -0.5f}, {1.0f, 1.0f, 1.0f}},
        {{0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
        {{0.5f, 0.5f}, {1.0f, 1.0f, 0.0f}},
        {{-0.5f, 0.5f}, {0.0f, 1.0f, 1.0f}}
    };;

    const vector<uint16_t> indices = {
        0, 1, 2, 0, 2, 3
    };
};