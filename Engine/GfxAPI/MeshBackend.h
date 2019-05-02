#pragma once
#include "Core/Backend.h"

// MeshBackend is the GfxAPI's representation of a mesh. When rendering a mesh to the screen,
// a pointer to an instance of MeshBackend should be given to the API.
class MeshBackend : public Backend {
public:
    MeshBackend();
    virtual ~MeshBackend();

private:

};
