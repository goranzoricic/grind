#include "PrecompiledHeader.h"

#include "Resources/ResourceManager.h"
#include "Resources/Resource.h"
#include "Resources/ResourcePtr.h"
#include "Resources/ResourcePtr.hpp"

// Initialize the singleton pointer to null.
std::unique_ptr<ResourceManager> ResourceManager::mgrUniqueInstance = nullptr;

// Get the resource manager singleton.
ResourceManager* ResourceManager::Instance() {
    // if the singleton instance hasn't been created, instantiate the singleton
    if (mgrUniqueInstance == nullptr) {
        mgrUniqueInstance = std::unique_ptr<ResourceManager>(new ResourceManager());
    }
    // return the singleton
    return mgrUniqueInstance.get();
}

// Initialize the resource manager.
ResourceManager::ResourceManager() noexcept {
    ResourcePtr<Resource> a((Resource*)32);
    a->GetName();
}

// Destroy the resource manager.
ResourceManager::~ResourceManager() {
    // nothing to do -- the resource map will clear in its destructor, thus removing references to all resources in it
    // TODO - use weak_ptr to check if all resources have been deleted after clearing the resource map
}


// Obtain a resource by its name. If it doesn't exist yet, create it, otherwise return the created one.
Resource *ResourceManager::ObtainResource(const std::string &strResourceName) {
    // return null if the resource isn't registered
    Resource *resResource = nullptr;
    // if a resource with the given name (path) exists in the manager, return that
    auto resResourceInstance = mapresResources.find(strResourceName);
    if (resResourceInstance != mapresResources.end()) {
        resResource = resResourceInstance->second;
    }    
    return resResource;
}


// Store a resource in the manager.
void ResourceManager::RegisterResource(Resource *presResource) {
    // check that the resource hasn't already been added
    auto resResourceInstance = mapresResources.find(presResource->GetName());
    assert(resResourceInstance != mapresResources.end());

    // add the resource to the map
    mapresResources[presResource->GetName()] = presResource;
}


// Release a reference to a resource. If the reference count reaches one (the last reference is from the resource manager), unload the resource and destroy it.
void ResourceManager::UnregisterResource(const Resource *resResource) {
    auto ctErased = mapresResources.erase(resResource->GetName());
    if (ctErased == 0) {
        throw std::runtime_error("[ResourceManager::ReleaseResource] releasing a resource that isn't stored in the manager!");
    }
}

