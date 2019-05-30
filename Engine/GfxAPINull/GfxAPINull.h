#pragma once
#include "../GfxAPI/GfxAPI.h"

// Implementation of the Null graphics api. It reports success on all commands, but doesn't actually do anything.
class GfxAPINull : public GfxAPI {
private:
    GfxAPINull() {};
    ~GfxAPINull() {};
    friend class GfxAPI;

public:
    // Initialize the API. Returns true if successfull.
    virtual bool Initialize(uint32_t dimWidth, uint32_t dimHeight);
    // Destroy the API. Returns true if successfull.
    virtual bool Destroy();

    // Render a frame.
    virtual void Render(RenderableDrawList& renderableDrawList);

    // Create the backend (API internal) representation for a frontend (external, API agnostic) mesh.
    virtual MeshBackend *CreateBackend(Mesh *resFrontend);
    // Destroy and unregister a mesh backend.
    virtual void DestroyBackend(MeshBackend *resbBackend);
	// Create the backend (API internal) representation for a frontend (external, API agnostic) shader.
	virtual ShaderBackend *CreateBackend(Shader* resFrontend, const std::string &strVertexProgram, const std::string &strPixelProgram);
	// Destroy and unregister a shader backend.
	virtual void DestroyBackend(ShaderBackend *resbBackend);
	// Create the backend (API internal) representation for a frontend (external, API agnostic) texture.
    virtual TextureBackend *CreateBackend(Texture *resFrontend, const unsigned char *aubTextureData);
    // Destroy and unregister a mesh backend.
    virtual void DestroyBackend(TextureBackend *resbBackend);
};



