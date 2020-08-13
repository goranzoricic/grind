#pragma once


#include "../Resources/Model.h"

// This class implements the Renderable. It provides the applciation with means to draw objects on screen.
// Anything that is to be drawn goes through here.
class Renderable {
public:
	// Default constructor, does not create an object that will render anything.
	Renderable() {};
	// Constructor accepting the name of the model this renderable will draw.
	Renderable(const std::string &strModelName);
	// Default destructor.
    virtual ~Renderable() {};


	// Getter for the model this renderable is drawing.
	ResourcePtr<Model> GetModel() { return _mdlModel; }

private:
	// Model that this renderable will draw.
	ResourcePtr<Model> _mdlModel;
};

