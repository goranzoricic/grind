#include "PrecompiledHeader.h"

#include "Resources/ResourcePtr.h"
#include "Resources/ResourcePtr.hpp"
#include "Resources/ResourceManager.h"
#include "GfxAPI/GfxAPI.h"

#include "GfxAPI/ShaderBackend.h"

#include "Resources/Shader.h"

// Factory function that creates a Shader resource. If a Shader resource with the given name is already stored in the
// ResourceManager, a new one won't be created. 
ResourcePtr<Shader> Shader::Obtain(const std::string &strShaderObjFile) {
    ResourceManager *mgrResourceManager = ResourceManager::Instance();
    // if the Shader doesn't exist in the resource manager
    Shader* resShader = dynamic_cast<Shader*>(mgrResourceManager->ObtainResource(strShaderObjFile));
    if (resShader == nullptr) {
        // create a new Shader and load its data from the .obj file
        resShader = new Shader(strShaderObjFile);
        resShader->LoadShader();
        // register it in the resource manager
        mgrResourceManager->RegisterResource(resShader);
    }
    // return a resource pointer to the Shader
    return ResourcePtr<Shader>(resShader);
}


Shader::Shader(const std::string &strResourceName) : Resource(strResourceName) {
    // just call the base constructor
}


// Virtual destructor that does cleanup.
Shader::~Shader() {
}


// Load the shader from a .shader file.
void Shader::LoadShader() {
	std::ifstream sInFile;
	sInFile.open(strName);

	// load the vertex program name
	std::string vertexProgram;
	sInFile >> vertexProgram;
	// load the pixel program name
	std::string pixelProgram;
	sInFile >> pixelProgram;

	// close the file before creating the backend
	sInFile.close();

	// create the backend representation of this shader
	backShader = GfxAPI::Get()->CreateBackend(this, vertexProgram, pixelProgram);
}


// Destroy the Shader. 
void Shader::Destroy() {
	// destroy the backend representation of this shader
	GfxAPI::Get()->DestroyBackend(backShader);
}
