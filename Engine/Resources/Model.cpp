#include "PrecompiledHeader.h"

#include "Resources/ResourcePtr.h"
#include "Resources/ResourcePtr.hpp"
#include "Resources/ResourceManager.h"
#include "Resources/Mesh.h"
#include "Resources/Texture.h"
#include "GfxAPI/GfxAPI.h"

#include "Resources/Model.h"

// Factory function that creates a model resource. If a model resource with the given name is already stored in the
// ResourceManager, a new one won't be created. 
ResourcePtr<Model> Model::Obtain(const std::string &strModelFile) {
    ResourceManager *mgrResourceManager = ResourceManager::Instance();
    // if the model doesn't exist in the resource manager
    Model* resModel = dynamic_cast<Model*>(mgrResourceManager->ObtainResource(strModelFile));
    if (resModel == nullptr) {
        // create a new model and load its data from the .obj file
        resModel = new Model(strModelFile);
        resModel->LoadModel();
        // register it in the resource manager
        mgrResourceManager->RegisterResource(resModel);
    }
    // return a resource pointer to the model
    return ResourcePtr<Model>(resModel);
}


Model::Model(const std::string &strResourceName) : Resource(strResourceName) {
    // just call the base constructor
}


// Virtual destructor that does cleanup.
Model::~Model() {
}


// Load the Model from a .model file.
void Model::LoadModel() {
	std::ifstream sInFile;
	sInFile.open(strName);

	std::string resourceName;
	// load the geometry
	sInFile >> resourceName;
	rpGeometry = Mesh::Obtain(resourceName);
	// load the texture
	sInFile >> resourceName;
	rpTexture = Texture::Obtain(resourceName);

	// close the file
	sInFile.close();
}


// Destroy the Model. 
void Model::Destroy() {
	// clear resource pointer
	rpGeometry = nullptr;
	rpTexture = nullptr;
}
