#include "PrecompiledHeader.h"
#include "Application.h"

#include <vector>
#include <stdexcept>
#include <functional>

#include "Config/Options.h"
#include "GfxAPI/GfxAPI.h"
#include "GfxAPI/Window.h"
#include "Resources/ResourcePtr.hpp"
#include "Renderer/Renderer.h"
#include "Renderer/Renderable.h"

// Run the application - initialize, run the main loop, cleanup at the end.
void Application::Run() {
    // start the graphics API
    InitializeGraphics();
	// obtain resources
	ObtainResources();
	// create the objects to render
	CreateRenderables();
	// program's main loop
    MainLoop();
    // clean up Vulkan API and destroy the application window
    Cleanup();
}


// Start the graphics API and create the window.
void Application::InitializeGraphics() {
    // create the graphics API selected in the options
    const Options &options = Options::Get();
    if (options.GetGfxAPIType() == GfxAPIType::GFX_API_TYPE_VULKAN) {
        apiGfxAPI = GfxAPI::CreateVulkan();
    } else if (options.GetGfxAPIType() == GfxAPIType::GFX_API_TYPE_NULL) {
        apiGfxAPI = GfxAPI::CreateNull();
    } else {
        throw std::runtime_error("Graphics API type not specified on options");
    }

    // initialize the API and let it create the window
    apiGfxAPI->Initialize(options.GetWindowWidth(), options.GetWindowHeight());

	// create the renderer
	const auto *renderer = Renderer::Create();
	assert(renderer != nullptr);
}

// Obtain resources used by the application.
void Application::ObtainResources() {
    rpMesh = Mesh::Obtain("../sphere.obj");
    rpMesh2 = Mesh::Obtain("../cube.obj");
	rpModel = Model::Obtain("../model.model");
	rpShader = Shader::Obtain("../shader.shader");
	rpTexture = Texture::Obtain("../uv_checker.png");
}


// Create the objects to render.
void Application::CreateRenderables() {
	_renderable = std::make_shared<Renderable>("../model.model");
	Renderer::Get()->addRenderable(_renderable);
}

// Destroy all renderables.
void Application::DestroyRenderables() {
	Renderer::Get()->removeRenderable(_renderable);
	_renderable == nullptr;
}

// Program's main loop
void Application::MainLoop() {
    // cache the graphics API
    GfxAPI *apiGfx = GfxAPI::Get();

	// loop until the user closes the window
    std::shared_ptr<Window> wndWindow = apiGfx->GetWindow();
	while (!wndWindow->ShouldClose()) {
        wndWindow->ProcessMessages();
		Renderer::Get()->Render();
	}
}

// Clear all resource pointers, to unload resources.
void Application::ReleaseResources()
{
	_renderable = nullptr;
	rpTexture = nullptr;
	rpShader = nullptr;
	rpModel = nullptr;
	rpMesh2 = nullptr;
	rpMesh = nullptr;
}

// Clean up Vulkan API and destroy the application window
void Application::Cleanup() {
	// clear all resource pointers, to have a gracefull exit
	ReleaseResources();
	// destroy the graphics API
	GfxAPI::Get()->Destroy();
}


