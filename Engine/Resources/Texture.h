#pragma once

#include "Resources/Resource.h"

class TextureBackend;

// Texture class is the engine-side representation of an image. It loads image data from a .png file
// and creates a GfxAPI backend representation of it. A Texture is a reference counted resource stored in the ResourceManager.
class Texture : public Resource {
public:
    // Information structure containing basic info of the texture;
    struct TextureDescription {
        int dimWidth = { 0 };
        int dimHeight = { 0 };
        int ctChannels = { 0 };
    };

public:
    // Factory function that creates a Texture resource. If a Texture resource with the given name is already stored in the
    // ResourceManager, a new one won't be created. 
    static ResourcePtr<Texture> Obtain(const std::string &strTextureObjFile);

private:
    // Construction is allowed only from the Obtain function which must supply a name.
    Texture(const std::string &strResourceName);


public:
    // Forbid default and copy construction and assignment, Texturees should be created only through 'Obtain' calls,
    // always allocated on heap and reference counted.
    Texture() = delete;
    Texture(const Texture &resOther) = delete;
    const Texture &operator=(const Texture &resOther) = delete;

    // Virtual destructor that does cleanup.
	virtual ~Texture();

    // Load the Texture from a .png file.
	void LoadPNG();

	// Get the Texture's information.
    const TextureDescription &GetTextureInfo() const { return infTextureDescription; }

private:
    // Destroy the Texture. 
    virtual void Destroy();

    // GfxAPI backed object for this Texture.
    TextureBackend *backTexture = { nullptr };

    // Texture's description - width, height, depth...
    TextureDescription infTextureDescription;
};
