#pragma once

#include "core_headers.h"
#include <vector>

class Mesh {
public:
    Mesh() {
        vertices = {
            // Front
            {-0.25f, -0.25f,  0.25f},
            { 0.25f, -0.25f,  0.25f},
            { 0.25f,  0.25f,  0.25f},
            {-0.25f,  0.25f,  0.25f},

            // Back
            { 0.25f, -0.25f, -0.25f},
            {-0.25f, -0.25f, -0.25f},
            {-0.25f,  0.25f, -0.25f},
            { 0.25f,  0.25f, -0.25f},

            // Top
            {-0.25f, -0.25f, -0.25f},
            { 0.25f, -0.25f, -0.25f},
            { 0.25f, -0.25f,  0.25f},
            {-0.25f, -0.25f,  0.25f},

            // Bottom
            {-0.25f,  0.25f,  0.25f},
            { 0.25f,  0.25f,  0.25f},
            { 0.25f,  0.25f, -0.25f},
            {-0.25f,  0.25f, -0.25f},

            // Right
            { 0.25f, -0.25f,  0.25f},
            { 0.25f, -0.25f, -0.25f},
            { 0.25f,  0.25f, -0.25f},
            { 0.25f,  0.25f,  0.25f},

            // Left
            {-0.25f, -0.25f, -0.25f},
            {-0.25f, -0.25f,  0.25f},
            {-0.25f,  0.25f,  0.25f},
            {-0.25f,  0.25f, -0.25f},
        };

        indices = {
            0,  1,  2,  2,  3,  0,  //Front
            4,  5,  6,  6,  7,  4,  //Back
            8,  9, 10, 10, 11,  8,  //Top
           12, 13, 14, 14, 15, 12,  //Bottom
           16, 17, 18, 18, 19, 16,  //Right
           20, 21, 22, 22, 23, 20,  //Left
        };

        uvs = {
            // Front
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},

            // Back
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},

            // Top
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},

            // Bottom
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},

            // Right
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},

            // Left
            {0.0f, 0.0f},
            {1.0f, 0.0f},
            {1.0f, 1.0f},
            {0.0f, 1.0f},
        };
    };

    std::vector<Vector3> getVertices();
    std::vector<uint16_t> getIndices();
    std::vector<Vector2> getUVs();

    bool isDirty();

    std::vector<Vector3> vertices;
    std::vector<uint16_t> indices;
    std::vector<Vector2> uvs;
private:

    bool _isDirty = false;
};