#include "PrecompiledHeader.h"
#include <vulkan/vulkan.h>

#include "GfxAPIVulkan/MeshBackendVulkan.h"
#include "GfxAPIVulkan/GfxAPIVulkan.h"


MeshBackendVulkan::MeshBackendVulkan() {
    
}

// Create Vulkan mesh backend for a loaded frontend mesh.
MeshBackendVulkan::MeshBackendVulkan(Mesh *resMeshFrontend) {
    // store the frontend mesh
    resFrontend = resMeshFrontend;
    // invoke the API to create vertex and index buffer from frontend mesh data
    GfxAPIVulkan::Get()->CreateVertexBuffer(resFrontend->GetVertices(), vkhVertexBuffer, vkhVertexBufferMemory);
    GfxAPIVulkan::Get()->CreateIndexBuffer(resFrontend->GetIndices(), vkhIndexBuffer, vkhIndexBufferMemory);
}

MeshBackendVulkan::~MeshBackendVulkan() {
    // destroy backend representation of a mesh
    GfxAPIVulkan::Get()->DestroyBuffer(vkhVertexBuffer, vkhVertexBufferMemory);
    vkhVertexBuffer = VK_NULL_HANDLE;
    vkhVertexBufferMemory = VK_NULL_HANDLE;
    GfxAPIVulkan::Get()->DestroyBuffer(vkhIndexBuffer, vkhIndexBufferMemory);
    vkhIndexBuffer = VK_NULL_HANDLE;
    vkhIndexBufferMemory = VK_NULL_HANDLE;
}


