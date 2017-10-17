#pragma once
#include "Resources/Resource.h"

// A resource pointer should never be default constructed. It should a always be give a pointer to an object.
template <class T>
ResourcePtr<T>::~ResourcePtr() {
    assert(presResource != nullptr);
    presResource->RemoveReference();
}


// Copy constructor, must add a reference to the new resource and remove one from the current one.
template <class T>
// Destroy the pointer, remove a reference form the pointed object.
ResourcePtr<T>::ResourcePtr(const ResourcePtr &presOther) {
    assert(presResource == nullptr);
    presResource = presOther.presResource;
    presResource->AddReference();
}


// Copy constructor, must add a reference to the new resource and remove one from the current one.
template <class T>
ResourcePtr<T>::ResourcePtr(T * const presOther) {
    assert(presResource == nullptr);
    presResource = presOther;
    presResource->AddReference();
}


// Assignment operator, same properties as the default constructor.
template <class T>
const ResourcePtr<T> &ResourcePtr<T>::operator = (const ResourcePtr &presOther) {
    // if the other pointer points to a different resource than this one
    if (presResource != presOther.presResource) {
        // remove the reference to the current object (it might get deleted)
        presResource->RemoveReference();
        // copy the pointer value
        presResource = presOther.presResource;
        // add a reference to the pointed object
        presResource->AddReference();
    }
    return *this;
}


// Assignment operator, same properties as the default constructor.
template <class T>
const ResourcePtr<T> &ResourcePtr<T>::operator = (T * const presOther) {
    // if the other pointer points to a different resource than this one
    if (presResource != presOther) {
        // remove the reference to the current object (it might get deleted)
        presResource->RemoveReference();
        // copy the pointer value
        presResource = presOther.presResource;
        // add a reference to the pointed object
        presResource->AddReference();
    }
    return *this;
}


// Referencing operator.
template <class T>
T *ResourcePtr<T>::operator->() {
    return presResource;
}





