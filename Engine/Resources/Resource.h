#pragma once

// Resoruce is a base class for all shared resources in the game (e.g. textures, meshes, models, fonts...).
// It is managed by ResourceManager and reference counted through the ResourcePtr class.
class Resource {
public:
    Resource();
    Resource(const std::string &strResoruceName);
    virtual ~Resource();

    // Get the resource's name.
    std::string GetName() const { return strName; }

protected:
    // ResorucePtr class is allowed to access the reference count and destroy a resource.
    template <class T>
    friend class ResourcePtr;

    // Resource's name.
    std::string strName;

    // Refence count for the resource.
    uint32_t ctReferences = { 0 };

    // Add a refrence to the resource.
    void AddReference();
    // Remove a reference from the resource, destroying it if it was the last reference.
    void RemoveReference();

    // Destroy the resource. Has to be overloaded by derived classes
    virtual void Destroy();
};
