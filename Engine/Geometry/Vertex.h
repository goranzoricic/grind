#pragma once

// This class describes one vertex of a Mesh.
struct Vertex {
    // Vertex position.
    glm::vec3 vecPosition;
    // Vertex color.
    glm::vec3 colColor;
    // Vertex UV coordinates.
    glm::vec2 vecTexCoords;
};