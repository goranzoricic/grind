#include "PrecompiledHeader.h"
#include <vulkan/vulkan.h>

#include "GfxAPIVulkan/TextureBackendVulkan.h"
#include "GfxAPIVulkan/GfxAPIVulkan.h"


TextureBackendVulkan::TextureBackendVulkan() {
    
}

// Create Vulkan mesh backend for a loaded frontend mesh.
TextureBackendVulkan::TextureBackendVulkan(Texture *resTextureFrontend, const unsigned char *aubTextureData) {
    // store the frontend mesh
    resFrontend = resTextureFrontend;
    // invoke the API to create texture data
    GfxAPIVulkan::Get()->CreateTextureImage(resTextureFrontend, aubTextureData, this);
}

TextureBackendVulkan::~TextureBackendVulkan() {
    // destroy backend representation of a texture
}


