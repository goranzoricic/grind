#pragma once
#include "GfxAPI/TextureBackend.h"

class Texture;

// TextureBackendVulkan is the Vulkan specific representation of a texture.
class TextureBackendVulkan : public TextureBackend {
public:
    TextureBackendVulkan();
    // Create Vulkan texture backend for a loaded frontend texture.
    TextureBackendVulkan(Texture *resTextureFrontend, const unsigned char *aubTextureData);
    virtual ~TextureBackendVulkan();


private:
    friend class GfxAPIVulkan;
    // Frontend mesh pair for this backend
    Texture *resFrontend = { nullptr };

    // Image holding the texture data.
    VkImage vkhImageData;
    // Memory used by the Image buffer.
    VkDeviceMemory vkhImageMemory;
    // Image view describing how to access the image.
    VkImageView vkhImageView;
    // Sampler used in the fragment shader to read from the texture.
    VkSampler vkhImageSampler;
};
