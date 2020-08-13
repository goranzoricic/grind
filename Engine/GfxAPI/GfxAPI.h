#pragma once

enum class GfxAPIType {
    GFX_API_TYPE_INVALID = -1,
    GFX_API_TYPE_NULL = 0,
    GFX_API_TYPE_VULKAN = 1,
};

class Window;

class Renderable;

class Mesh;
class MeshBackend;
class Shader;
class ShaderBackend;
class Texture;
class TextureBackend;

// This is a base class for graphics APIs. It defines the interface that an API needs to provide
// for the application and the render. The class is abstract, all required methods need to be implemented
// by concrete classes.
class GfxAPI {
protected:
    // Constructor and destructor are only available to derived classes.
    GfxAPI() {};
    virtual ~GfxAPI() {};

public:
    // Forbid the copy constructor and assignment to prevent multiple copies.
    GfxAPI(GfxAPI const &) = delete;
    void operator = (GfxAPI const &) = delete;

	// Type of the renderable pointer and the list of renderables to draw.
	using RenderablePtr = std::shared_ptr<Renderable>;
	using RenderableDrawList = std::vector<RenderablePtr>;

// Public interface.
public:
    // Get the current graphics API instance.
    static GfxAPI *Get();

    // Create a Vulkan graphics API.
    static GfxAPI *CreateVulkan();
    // Create a Null graphics API.
    static GfxAPI *CreateNull();

    // Initialize the API. Returns true if successfull. Pass window dimensions.
    virtual bool Initialize(uint32_t dimWidth, uint32_t dimHeight) = 0;
    // Destroy the API. Returns true if successfull.
    virtual bool Destroy() = 0;
    // Get the main application window.
    std::shared_ptr<Window> &GetWindow() { return _wndWindow;  }

    // Render a frame.
    virtual void Render(RenderableDrawList& renderableDrawList) = 0;

    // Create the backend (API internal) representation for a frontend (external, API agnostic) mesh.
    virtual MeshBackend *CreateBackend(Mesh *resFrontend) = 0;
    // Destroy and unregister a mesh backend.
    virtual void DestroyBackend(MeshBackend *resbBackend) = 0;
	// Create the backend (API internal) representation for a frontend (external, API agnostic) shader.
	virtual ShaderBackend *CreateBackend(Shader* resFrontend, const std::string &strVertexProgram, const std::string &strPixelProgram) = 0;
	// Destroy and unregister a shader backend.
	virtual void DestroyBackend(ShaderBackend *resbBackend) = 0;
	// Create the backend (API internal) representation for a frontend (external, API agnostic) texture.
    virtual TextureBackend *CreateBackend(Texture *resFrontend, const unsigned char *aubTextureData) = 0;
    // Destroy and unregister a mesh backend.
    virtual void DestroyBackend(TextureBackend *resbBackend) = 0;

protected:
    // Application window
    std::shared_ptr<Window> _wndWindow;

    // The currently active graphics API implementation. There can be only one.
    static GfxAPI *_apiInstance;

};

