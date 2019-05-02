#include "../PrecompiledHeader.h"
#include "GfxAPINull.h"

#include "GfxAPI/MeshBackend.h"


// Initialize the API. Returns true if successfull.
bool GfxAPINull::Initialize(uint32_t dimWidth, uint32_t dimHeight) {
    return true;
}


// Destroy the API. Returns true if successfull.
bool GfxAPINull::Destroy() {
    return true;
}

// Render a frame.
void GfxAPINull::Render() {
    return;
}

// Create the backend (API internal) representation for a frontend (external, API agnostic) mesh.
MeshBackend *GfxAPINull::CreateBackend(Mesh *resFrontend) {
    return nullptr;
}

// Destroy and unregister a mesh backend.
void GfxAPINull::DestroyBackend(MeshBackend *resbBackend) {

}

// Create the backend (API internal) representation for a frontend (external, API agnostic) texture.
TextureBackend *GfxAPINull::CreateBackend(Texture *resFrontend, const unsigned char *aubTextureData) {
    return nullptr;
}

// Destroy and unregister a mesh backend.
void GfxAPINull::DestroyBackend(TextureBackend *resbBackend) {

}
