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

MeshBackend *GfxAPINull::CreateBackend(const Mesh *resFrontend) {
    return nullptr;
}
