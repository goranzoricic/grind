#pragma once

// Resoruce is a base class for all shared resources in the game (e.g. textures, meshes, models, fonts...).
// It is managed by ResourceManager and reference counted through the ResourcePtr class.
class Resource {
public:
    Resource();
    virtual ~Resource();

    // Get the resource's name.
    std::string GetName() { return strName; }

private:
    // ResorucePtr class is allowed to access the reference count and destroy a resource.
    template <class T>
    friend class ResourcePtr;

    // Resource's name.
    std::string strName;

    // Refence count for the resource.
    uint32_t ctReferences;
    void AddReference() {};
    void RemoveReference() {};
    // Destroy the resource. Has to be overloaded by concrete classes
    virtual void Destroy() = 0;
};
