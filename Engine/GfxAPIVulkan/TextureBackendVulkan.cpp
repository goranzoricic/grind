#include "PrecompiledHeader.h"
#include <vulkan/vulkan.h>

#include "GfxAPIVulkan/TextureBackendVulkan.h"
#include "GfxAPIVulkan/GfxAPIVulkan.h"


TextureBackendVulkan::TextureBackendVulkan() {
    
}

// Create Vulkan texture backend for a loaded frontend texture.
TextureBackendVulkan::TextureBackendVulkan(Texture *resTextureFrontend, const unsigned char *aubTextureData) {
    // store the frontend texture
    resFrontend = resTextureFrontend;
    // invoke the API to create texture data
    GfxAPIVulkan::Get()->CreateTextureImage(resTextureFrontend, aubTextureData, this);
}

TextureBackendVulkan::~TextureBackendVulkan() {
    // destroy backend representation of a texture
    GfxAPIVulkan::Get()->DestroyTextureImage(this);
}


