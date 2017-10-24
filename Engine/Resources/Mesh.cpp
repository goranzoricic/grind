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
        resMesh = new Mesh(strMeshObjFile);
        resMesh->LoadOBJ();
        // register it in the resource manager
        mgrResourceManager->RegisterResource(resMesh);
    }
    // return a resource pointer to the mesh
    return ResourcePtr<Mesh>(resMesh);
}


Mesh::Mesh(const std::string &strResourceName) : Resource(strResourceName) {
    // just call the base constructor
}


// Virtual destructor that does cleanup.
Mesh::~Mesh() {
}


// Load the mesh from an .obj file.
void Mesh::LoadOBJ() {
    // vertex attributes - position, normal, uv, color
    tinyobj::attrib_t vatrVertexAttributes;
    // object's meshes, named
    std::vector<tinyobj::shape_t> ameshMeshes;
    // materials used by the object
    std::vector<tinyobj::material_t> amatMaterials;
    // error string will be stored here, if any
    std::string strError;

    // load the model from the object file
    if (!tinyobj::LoadObj(&vatrVertexAttributes, &ameshMeshes, &amatMaterials, &strError, strName.data())) {
        throw std::runtime_error("Failed to load the model:  " + strError);
    }

    // combine all meshes into a single vertex and index buffer
    // go through all vertices in all meshes in the model
    for (const auto &meshMesh : ameshMeshes) {
        for (const auto iVertex : meshMesh.mesh.indices) {
            // read vertex attributes
            Vertex vVertex = {};
            // read the position
            vVertex.vecPosition = {
                vatrVertexAttributes.vertices[iVertex.vertex_index * 3 + 0],
                vatrVertexAttributes.vertices[iVertex.vertex_index * 3 + 1],
                vatrVertexAttributes.vertices[iVertex.vertex_index * 3 + 2],
            };
            // read the UV coordinaets
            vVertex.vecTexCoords = {
                vatrVertexAttributes.texcoords[iVertex.texcoord_index * 2 + 0],
                1.0f - vatrVertexAttributes.texcoords[iVertex.texcoord_index * 2 + 1],
            };
            // use constant color, white
            vVertex.colColor = { 1.0f, 1.0f, 1.0f };

            // store vertex and its index
            avVertices.push_back(vVertex);
            aiIndices.push_back(static_cast<uint32_t>(aiIndices.size()));
        }
    }

    // create the backend representation of this mesh
    backMesh = GfxAPI::Get()->CreateBackend(this);
}


// Destroy the mesh. 
void Mesh::Destroy() {

}
