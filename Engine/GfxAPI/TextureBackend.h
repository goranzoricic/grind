#pragma once
#include "Core/Backend.h"

// TextureBackend is the GfxAPI's representation of a texture. When rendering a mesh to the screen,
// a pointer to an instance of TextureBackend should be given to the API.
// The backend is responsible for storing texture data, frontend representation is responsible or loading it from disk.
class TextureBackend : public Backend {
public:
    TextureBackend();
    virtual ~TextureBackend();

private:

};
