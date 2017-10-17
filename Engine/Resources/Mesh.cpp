#include "PrecompiledHeader.h"

#include "Resources/ResourcePtr.h"
#include "Resources/ResourcePtr.hpp"
#include "Resources/ResourceManager.h"
#include "GfxAPI/GfxAPI.h"

#include "GfxAPI/MeshBackend.h"

#include "Resources/Mesh.h"

// Factory function that creates a mesh resource. If a mesh resource with the given name is already stored in the
// ResourceManager, a new one won't be created. 
ResourcePtr<Mesh> Mesh::Obtain(const std::string &strMeshObjFile) {
    ResourceManager *mgrResourceManager = ResourceManager::Instance();
    // if the mesh doesn't exist in the resource manager
    Mesh* resMesh = dynamic_cast<Mesh*>(mgrResourceManager->ObtainResource(strMeshObjFile));
    if (resMesh == nullptr) {
        // create a new mesh and load its data from the .obj file
        resMesh = new Mesh();
        resMesh->LoadOBJ(strMeshObjFile);
        // register it in the resource manager
        mgrResourceManager->RegisterResource(resMesh);
    }
    // return a resource pointer to the mesh
    return ResourcePtr<Mesh>(resMesh);
}


// Virtual destructor that does cleanup.
Mesh::~Mesh() {
}


// Load the mesh from an .obj file.
void Mesh::LoadOBJ(const std::string &strMeshObjFile) {
    backMesh = GfxAPI::Get()->CreateBackend(this);
}


// Destroy the mesh. 
void Mesh::Destroy() {

}
