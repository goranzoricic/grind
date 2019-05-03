#pragma once

#include <vector>
#include <vulkan/vulkan.h>
#include "Resources/ResourcePtr.h"
#include "Resources/Mesh.h"
#include "Resources/Model.h"
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
    // Obtain resources used by the application.
    void ObtainResources();
	// Create the objects to render.
	void CreateRenderables();
	// Program's main loop
	void MainLoop();
	// Clean up Vulkan API and destroy the application window
	void Cleanup();

private:
    ResourcePtr<Mesh> rpMesh = { nullptr };
    ResourcePtr<Mesh> rpMesh2 = { nullptr };
    ResourcePtr<Model> rpModel = { nullptr };
    ResourcePtr<Texture> rpTexture = { nullptr };

	std::unique_ptr<Renderable> _renderable;
};
