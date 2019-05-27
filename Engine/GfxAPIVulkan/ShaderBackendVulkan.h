#pragma once
#include "GfxAPI/ShaderBackend.h"

class Shader;

// ShaderBackendVulkan is the Vulkan specific representation of a shader.
class ShaderBackendVulkan : public ShaderBackend {
public:
    ShaderBackendVulkan();
    // Create Vulkan shader backend with specified programs.
	ShaderBackendVulkan(Shader* resShaderFrontend, const std::string &strVertexProgram, const std::string &strPixelProgram);
	virtual ~ShaderBackendVulkan();

private:
    friend class GfxAPIVulkan;

	// Frontend mesh pair for this backend
	Shader *resFrontend = { nullptr };

	// Layout of the graphics pipeline.
	VkPipelineLayout vkhPipelineLayout = { VK_NULL_HANDLE };
	// Graphics pipeline.
	VkPipeline vkhPipeline = { VK_NULL_HANDLE };
};
