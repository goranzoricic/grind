#pragma once

#include "Resources/Resource.h"

class MeshBackend;

// Mesh class is the engine-side representation of object geometry. It loads geometry data from an .obj file
// and creates a GfxAPI backend representation of it. A Mesh is a reference counted resource stored in the ResourceManager.
class Mesh : public Resource {
public:
    // Factory function that creates a mesh resource. If a mesh resource with the given name is already stored in the
    // ResourceManager, a new one won't be created. 
    static ResourcePtr<Mesh> Obtain(const std::string &strMeshObjFile);

private:
    // Default construction is allowed only from the Obtain function.
    Mesh() = default;

public:
    // Forbid copy construction and assignment, meshes should be created only through 'Obtain' calls,
    // always allocated on heap and reference counted.
    Mesh(const std::string &strMeshObjFile) = delete;
    const Mesh &operator=(const Mesh &resOther) = delete;

    // Virtual destructor that does cleanup.
	virtual ~Mesh();

    // Load the mesh from an .obj file.
	void LoadOBJ(const std::string &strMeshObjFile);

private:
    // Destroy the mesh. 
    virtual void Destroy();

    // GfxAPI backed object for this mesh.
    MeshBackend *backMesh = { nullptr };
};
