#pragma once
#include <vector>
#include "vulkan_engine_headers.h"
#include "mesh.h"

struct Vertex {
    glm::vec3 pos;
    glm::vec2 texCoord;

    static VkVertexInputBindingDescription getBindingDescription() {
        VkVertexInputBindingDescription bindingDescription{};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;


        return bindingDescription;
    }

    static std::array<VkVertexInputAttributeDescription, 2> getAttributeDescriptions() {
        std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions{};

        //Vertex attribute
        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Vertex, pos);

        //UV attribute
        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Vertex, texCoord);

        return attributeDescriptions;
    }
};

class GPUMesh {
public:
	GPUMesh(Mesh* mesh) {
        for (int i = 0; i < mesh->getVertices().size(); i++){
            vertices.push_back({ {
                    mesh->getVertices()[i].x,
                    mesh->getVertices()[i].y,
                    mesh->getVertices()[i].z}, 
                {
                    mesh->getUVs()[i].x,
                    mesh->getUVs()[i].y
                }});
        }

        indices = mesh->getIndices();
	}

    //per mesh data
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    //per object data
    glm::mat4 model = glm::mat4(1.0f);

private:
};