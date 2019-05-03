#include "../PrecompiledHeader.h"

#include "Renderable.h"


// Constructor accepting the name of the model this renderable will draw.
Renderable::Renderable(const std::string &strModelName) {
	_mdlModel = Model::Obtain(strModelName);
}
