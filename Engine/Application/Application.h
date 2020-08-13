#pragma once

#include <vector>
#include <vulkan/vulkan.h>
#include "Resources/ResourcePtr.h"
#include "Resources/Mesh.h"
#include "Resources/Model.h"
#include "Resources/Shader.h"
#include "Resources/Texture.h"
#include "Renderer/Renderable.h"

class Renderable;

class Application {
public:
    Application() : apiGfxAPI(nullptr) {}

    // Run the application - initialize, run the main loop, cleanup at the end.
	void Run();

private:
    // Grapics API to use in the application.
    class GfxAPI *apiGfxAPI;

    // Start the graphics API and create the window.
    void InitializeGraphics();

private:
	// Obtain resources used by the application.
	void ObtainResources();
	// Create the objects to render.
	void CreateRenderables();
	// Destroy all renderables.
	void DestroyRenderables();
	// Program's main loop
	void MainLoop();
	// Clear all resource pointers, to unload resources.
	void ReleaseResources();
	// Clean up Vulkan API and destroy the application window.
	void Cleanup();

	ResourcePtr<Mesh> rpMesh = { nullptr };
    ResourcePtr<Mesh> rpMesh2 = { nullptr };
    ResourcePtr<Model> rpModel = { nullptr };
	ResourcePtr<Shader> rpShader = { nullptr };
	ResourcePtr<Texture> rpTexture = { nullptr };

	std::shared_ptr<Renderable> _renderableSphere;
	std::shared_ptr<Renderable> _renderableCube;
};
