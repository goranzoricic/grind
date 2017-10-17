#pragma once
#include "GfxAPI/MeshBackend.h"

// MeshBackendVulkanis the Vulkan specific representation of a mesh, ready for rendering.
class MeshBackendVulkan : public MeshBackend {
public:
    MeshBackendVulkan();
    virtual ~MeshBackendVulkan();

private:
};
