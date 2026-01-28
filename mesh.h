#pragma once

#include "core_headers.h"
#include <vector>

class Mesh {
public:
    Mesh() {
        vertices = {
            {0.5f, -0.5f, 0.5f},   //Top left
            {-0.5f, -0.5f, 0.5f},  //Top right
            {0.5f, 0.5f, 0.5f},    //Bottom left
            {-0.5f, 0.5f, 0.5f},   //Bottom right

            {0.5f, -0.5f, -0.5f},  //Top left
            {-0.5f, -0.5f, -0.5f}, //Top right
            {0.5f, 0.5f, -0.5f},   //Bottom left
            {-0.5f, 0.5f, -0.5f},  //Bottom right
        };

        indices = {
            2, 1, 0, 1, 2, 3, //Top
            4, 5, 6, 7, 6, 5, //Bottom
            4, 2, 0, 2, 4, 6, //Left
            1, 3, 5, 7, 5, 3, //Right
            6, 3, 2, 3, 6, 7, //Front
            0, 1, 4, 5, 4, 1, //Back
        };

        uvs = {
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {0.0f, 1.0f},
            {1.0f, 1.0f},

            {1.0f, 0.0f},
            {0.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},
        };
    };

    std::vector<Vector3> getVertices();
    std::vector<uint16_t> getIndices();
    std::vector<Vector2> getUVs();

    bool isDirty();

private:
    std::vector<Vector3> vertices;
    std::vector<uint16_t> indices;
    std::vector<Vector2> uvs;

    bool _isDirty = false;
};