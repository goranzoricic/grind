#include "PrecompiledHeader.h"

#include "Resources/ResourcePtr.h"
#include "Resources/ResourcePtr.hpp"
#include "Resources/ResourceManager.h"
#include "GfxAPI/GfxAPI.h"

#include "GfxAPI/TextureBackend.h"

#include "Resources/Texture.h"

// Factory function that creates a Texture resource. If a Texture resource with the given name is already stored in the
// ResourceManager, a new one won't be created. 
ResourcePtr<Texture> Texture::Obtain(const std::string &strTextureObjFile) {
    ResourceManager *mgrResourceManager = ResourceManager::Instance();
    // if the Texture doesn't exist in the resource manager
    Texture* resTexture = dynamic_cast<Texture*>(mgrResourceManager->ObtainResource(strTextureObjFile));
    if (resTexture == nullptr) {
        // create a new Texture and load its data from the .obj file
        resTexture = new Texture(strTextureObjFile);
        resTexture->LoadPNG();
        // register it in the resource manager
        mgrResourceManager->RegisterResource(resTexture);
    }
    // return a resource pointer to the Texture
    return ResourcePtr<Texture>(resTexture);
}


Texture::Texture(const std::string &strResourceName) : Resource(strResourceName) {
    // just call the base constructor
}


// Virtual destructor that does cleanup.
Texture::~Texture() {
}


// Load the Texture from an .obj file.
void Texture::LoadPNG() {
    // load the image ising the stb library
    unsigned char *imgRawData = stbi_load(strName.data(), &infTextureDescription.dimWidth, &infTextureDescription.dimHeight, &infTextureDescription.ctChannels, STBI_rgb_alpha);

    // if the image failed to load, throw an exception
    if (!imgRawData) {
        throw std::runtime_error("Failed to load the texture: " + strName);
    }

    // create the backend representation of this Texture
    backTexture = GfxAPI::Get()->CreateBackend(this, imgRawData);

    // release texture memory
    stbi_image_free(imgRawData);
}


// Destroy the Texture. 
void Texture::Destroy() {
	// destroy the backend representation of this texture
	GfxAPI::Get()->DestroyBackend(backTexture);
}
