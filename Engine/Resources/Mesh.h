#pragma once

#include "Resources/Resource.h"
#include "Geometry/Vertex.h"

class MeshBackend;

// Mesh class is the engine-side representation of object geometry. It loads geometry data from an .obj file
// and creates a GfxAPI backend representation of it. A Mesh is a reference counted resource stored in the ResourceManager.
class Mesh : public Resource {
public:
    // Factory function that creates a mesh resource. If a mesh resource with the given name is already stored in the
    // ResourceManager, a new one won't be created. 
    static ResourcePtr<Mesh> Obtain(const std::string &strMeshObjFile);

private:
    // Construction is allowed only from the Obtain function which must supply a name.
    Mesh(const std::string &strResourceName);


public:
    // Forbid default and copy construction and assignment, meshes should be created only through 'Obtain' calls,
    // always allocated on heap and reference counted.
    Mesh() = delete;
    Mesh(const Mesh &resOther) = delete;
    const Mesh &operator=(const Mesh &resOther) = delete;

    // Virtual destructor that does cleanup.
	virtual ~Mesh();

    // Load the mesh from an .obj file.
	void LoadOBJ();

    // Get the mesh'es vertices.
    const std::vector<Vertex> &GetVertices() { return avVertices;  }
    // Get the mesh'es indices.
    const std::vector<uint32_t> &GetIndices() { return aiIndices; }

	// getter for the backend. Note that this is not a virtual function.
	MeshBackend *GetBackend() { return backMesh; }

private:
    // Destroy the mesh. 
    virtual void Destroy();

    // GfxAPI backed object for this mesh.
    MeshBackend *backMesh = { nullptr };

    // Array of vertices belonging to this mesh
    std::vector<Vertex> avVertices;
    // Array of vertex indices defining the mesh.
    std::vector<uint32_t> aiIndices;

};
