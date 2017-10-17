#include "PrecompiledHeader.h"

#include "Resources/Mesh.h"
#include "Resources/ResourceManager.h"


std::shared_ptr<Mesh> Mesh::Create(const std::string &strMeshObjFile) {
    std::shared_ptr<Mesh> resMesh = std::make_shared<Mesh>(strMeshObjFile);
    return resMesh;
}


Mesh::Mesh() {
}


Mesh::Mesh(const std::string &strMeshObjFile) {
}


Mesh::~Mesh() {
}


void Mesh::LoadOBJ(const std::string &strMeshObjFile) {

}

