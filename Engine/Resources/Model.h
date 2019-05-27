#pragma once

#include "Resources/Mesh.h"
#include "Resources/Texture.h"

// Model represents an object rendered on the screen, consisting of geometry and materials.
class Model : public Resource {
public:
    // Factory function that creates a model resource. If a model resource with the given name is already stored in the
    // ResourceManager, a new one won't be created. 
    static ResourcePtr<Model> Obtain(const std::string &strModelFile);

private:
    // Construction is allowed only from the Obtain function which must supply a name.
    Model(const std::string &strResourceName);


public:
    // Forbid default and copy construction and assignment, models should be created only through 'Obtain' calls,
    // always allocated on heap and reference counted.
    Model() = delete;
    Model(const Model &resOther) = delete;
    const Model &operator=(const Model &resOther) = delete;

    // Virtual destructor that does cleanup.
	virtual ~Model();

    // Load the model from a .model file.
	void LoadModel();

private:
    // Destroy the Model. 
    virtual void Destroy();

	// Geometry representing the model.
	ResourcePtr<Mesh> rpGeometry;
	// Texture to use to render the model with.
	ResourcePtr<Texture> rpTexture;
};
