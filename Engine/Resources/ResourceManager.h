#pragma once

#include "Resources/Resource.h"

// ResourceManager is a singleton class that manages all shared resources. A resource is any object derived from the Resource class
// that is able to be obtained (either through loading or in-process creation) and released. All resources are reference counted
// and, naturally, destroyed when their reference count reaches zero.
class ResourceManager {
public:
    // Get the resource manager singleton.
    static ResourceManager* Instance();
    // Default destructor must be publicly available.
    ~ResourceManager();

private:
    // Disable resource manager creation outside of its methids, to ensure it stays a singleton.
    ResourceManager() noexcept;
    ResourceManager(const ResourceManager &mgrResourceManager) = delete;
    ResourceManager &operator =(const ResourceManager &mgrResourceManager) = delete;
    
public:
    // Obtain a resource by its name. If it doesn't exist yet, create it, otherwise return the created one.
    template <class T>
    std::shared_ptr<T> ObtainResource(const std::string &strResourceName);

    // Release a reference to a resource. If the reference count reaches one (the last reference is from the resource manager), unload the resource and destroy it.
    template <class T>
    void ReleaseResource(const std::weak_ptr<T> &resResource);

private:
    // Store a resource in the manager.
    template <class T>
    void StoreResource(const std::string &key, const std::shared_ptr<T> &presResource);

private:
    // Resource manager singleton.
    static std::unique_ptr<ResourceManager> mgrUniqueInstance;
    
    // Map of all currently active resources.
    std::unordered_map<std::string, std::weak_ptr<Resource> > mapresResources;
};
