#include "PrecompiledHeader.h"
#include <vulkan/vulkan.h>

#include "GfxAPIVulkan/ShaderBackendVulkan.h"
#include "GfxAPIVulkan/GfxAPIVulkan.h"


ShaderBackendVulkan::ShaderBackendVulkan() {
    
}

// Create Vulkan texture backend for a loaded frontend texture.
ShaderBackendVulkan::ShaderBackendVulkan(Shader* resShaderFrontend, const std::string &strVertexProgram, const std::string &strPixelProgram) {
	// store the frontend shader
	resFrontend = resShaderFrontend;

	// let the API create all required resources for the shader
	GfxAPIVulkan::Get()->CreateShader(this, strVertexProgram, strPixelProgram);
}

ShaderBackendVulkan::~ShaderBackendVulkan() {
	// let the API destroy all resources allocated by this shader
	GfxAPIVulkan::Get()->DestroyShader(this);
}


