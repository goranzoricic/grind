#pragma once

// Backend is a base class for all API specific representations of engine object
// For example, meshes and textures have GfxAPI backends, actors and shapes have PhysX backends, etc.
class Backend {
public:
    Backend();
    virtual ~Backend();

private:

};
