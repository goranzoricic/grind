#pragma once

#include "Resources/Resource.h"


class Mesh : public Resource
{
public:
    static std::shared_ptr<Mesh> Create(const std::string &strMeshObjFile);
    
public:
	Mesh();
	Mesh(const std::string &strMeshObjFile);
	~Mesh();

	void LoadOBJ(const std::string &strMeshObjFile);

private:
    // Destroy the resource. Has to be overloaded by concrete classes
    virtual void Destroy() {};
};
