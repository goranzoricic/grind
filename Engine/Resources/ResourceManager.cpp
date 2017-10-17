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
template <class T>
std::shared_ptr<T> ResourceManager::ObtainResource(const std::string &strResourceName) {
    std::shared_ptr<T> resResource;
    // if a resource with the given name (path) exists in the manager, return that
    auto resResourceInstance = mapresResources.find(strResourceName);
    if (resResourceInstance != mapresResources.end()) {
        resResource = resResource->second;
    // else, create a new resource with the given name and return it
    } else {
        resResource = T::Create(strResourceName);
    }
    return resResource;
}


// Release a reference to a resource. If the reference count reaches one (the last reference is from the resource manager), unload the resource and destroy it.
template <class T>
void ResourceManager::ReleaseResource(const std::weak_ptr<T> &resResource) {
    //
    auto resLocked = resResource.lock();
    auto ctErased = mapresResources.erase(resLocked->GetName());
    if (ctErased == 0) {
        throw std::runtime_error("ResourceManager::ReleaseResource releasing a resource that isn't stored in the manager!");
    }
}

// Store a resource in the manager.asdasd
template <class T>
void ResourceManager::StoreResource(const std::string &key, const std::shared_ptr<T> &presResource) {
    if (ObtainResource(key) != nullptr) {
        throw std::runtime_error("ResourceManager::StoreResource storing resource already in the manager!");
    }
    mapresResources[key] = presResource;
}
