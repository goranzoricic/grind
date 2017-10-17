#include "PrecompiledHeader.h"

#include "Resources/Resource.h"
#include "Resources/ResourceManager.h"

Resource::Resource() {
    
}

Resource::~Resource() {
    assert(ctReferences == 0);
}


// Add a refrence to the resource.
void Resource::AddReference() {
    assert(ctReferences > 0);
    ++ctReferences;
}


// Remove a reference from the resource, destroying it if it was the last reference.
void Resource::RemoveReference() {
    assert(ctReferences > 0);

    --ctReferences;
    if (ctReferences == 0) {
        Destroy();
    }
}


// Destroy the resource. Has to be overloaded by derived classes
void Resource::Destroy() {
    ResourceManager::Instance()->UnregisterResource(this);
}







