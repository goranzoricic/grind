#pragma once

#include "Renderable.h"

class GfxAPI;
enum class GfxAPIType;

// This class implements the renderer. It provides the applciation with means to draw objects on screen.
// Anything that is to be drawn goes through here.
class Renderer {
protected:
    // Constructor and destructor are only available to derived classes.
    Renderer() {};
    virtual ~Renderer() {};

public:
    // Forbid the copy constructor and assignment to prevent multiple copies.
    Renderer(Renderer const &) = delete;
    void operator = (Renderer const &) = delete;

// Public interface.
public:
    // Get the current graphics API instance.
    static Renderer *Get();
    // Create a Vulkan graphics API.
    static Renderer *Create();

	// Add a renderable to be drawn.
	void addRenderable(const std::shared_ptr<Renderable> &renderable);
	// Remove a renderable fromthe renderer.
	void removeRenderable(const std::shared_ptr<Renderable> &renderable);

	// Render a frame.
    virtual void Render();

protected:
    // The active renderer instance. There can be only one.
    static Renderer* _renInstance;
	
	// Collection of all renderables that are drawn each frame.
	std::vector<std::shared_ptr<Renderable>> _arenRenderables;
};

