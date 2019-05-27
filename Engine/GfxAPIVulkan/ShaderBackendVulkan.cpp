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

    // invoke the API to create pipeline data
    GfxAPIVulkan::Get()->CreateGraphicsPipeline(strVertexProgram, strPixelProgram, this);
}

ShaderBackendVulkan::~ShaderBackendVulkan() {
    // destroy backend representation of a texture
    GfxAPIVulkan::Get()->DestroyGraphicsPipeline(this);
}


