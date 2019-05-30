#include "../PrecompiledHeader.h"

#include "Renderer.h"


Renderer* Renderer::_renInstance = { nullptr };

// Get the current graphics API instance.
Renderer *Renderer::Get() {
	assert(_renInstance != nullptr);
	return _renInstance;
}


// Create a Vulkan graphics API.
Renderer *Renderer::Create() {
	assert(_renInstance == nullptr);
	_renInstance = new Renderer();
	return _renInstance;
}


// Add a renderable to be drawn.
void Renderer::addRenderable(const std::shared_ptr<Renderable> &renderable) {
	assert(std::find(_arenRenderables.begin(), _arenRenderables.end(), renderable) == _arenRenderables.end());
	_arenRenderables.emplace_back(renderable);
}


// Remove a renderable fromthe renderer.
void Renderer::removeRenderable(const std::shared_ptr<Renderable> &renderable) {
	auto itRenderable = std::find(_arenRenderables.begin(), _arenRenderables.end(), renderable);
	assert(itRenderable != _arenRenderables.end());
	_arenRenderables.erase(itRenderable);
}


// Render a frame.
void Renderer::Render() {
	GfxAPI::Get()->Render(_arenRenderables);
}
