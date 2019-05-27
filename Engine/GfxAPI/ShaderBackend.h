#pragma once
#include "Core/Backend.h"

// ShaderBackend is the GfxAPI's representation of a shader. When rendering a mesh to the screen,
// a a pointer to a shader backend resource is provided, to declare the rendering technique to draw with.
// The backend is responsible for managing shader data, frontend representation is responsible or loading it from disk.
class ShaderBackend : public Backend {
public:
    ShaderBackend();
    virtual ~ShaderBackend();

private:

};
