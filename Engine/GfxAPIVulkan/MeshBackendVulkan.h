#pragma once
#include "GfxAPI/MeshBackend.h"

class Mesh;

// MeshBackendVulkanis the Vulkan specific representation of a mesh, ready for rendering.
class MeshBackendVulkan : public MeshBackend {
public:
    MeshBackendVulkan();
    // Create Vulkan mesh backend for a loaded frontend mesh.
    MeshBackendVulkan(Mesh *resMeshFrontend);
    virtual ~MeshBackendVulkan();

private:
    // Frontend mesh pair for this backend
    Mesh *resFrontend = { nullptr };

    // Vertex buffer holding the mesh'es vertices.
    VkBuffer vkhVertexBuffer;
    // Memory used by the vertex buffer.
    VkDeviceMemory vkhVertexBufferMemory;

    // Index buffer holding the order of vertices in triangles.
    VkBuffer vkhIndexBuffer;
    // Memory used by the index buffer.
    VkDeviceMemory vkhIndexBufferMemory;
};
