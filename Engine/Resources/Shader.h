#pragma once

#include "Resources/Resource.h"

class ShaderBackend;

// A shader is a representation of a rendering technique. It consists of actual shader code, pipelines and render passes.
class Shader : public Resource {
public:
    // Factory function that creates a shader resource. If a shader resource with the given name is already stored in the
    // ResourceManager, a new one won't be created. 
    static ResourcePtr<Shader> Obtain(const std::string &strShaderObjFile);

private:
    // Construction is allowed only from the Obtain function which must supply a name.
    Shader(const std::string &strResourceName);


public:
    // Forbid default and copy construction and assignment, shaderes should be created only through 'Obtain' calls,
    // always allocated on heap and reference counted.
    Shader() = delete;
    Shader(const Shader &resOther) = delete;
    const Shader &operator=(const Shader &resOther) = delete;

    // Virtual destructor that does cleanup.
	virtual ~Shader();

    // Load the shader from a .shader file.
	void LoadShader();

	// getter for the backend. Note that this is not a virtual function.
	ShaderBackend *GetBackend() { return backShader; }

private:
    // Destroy the Shader. 
    virtual void Destroy();

    // GfxAPI backed object for this Shader.
    ShaderBackend *backShader = { nullptr };
};
