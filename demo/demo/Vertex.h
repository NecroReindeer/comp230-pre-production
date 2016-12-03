#pragma once
//! Class for Vertices.
/*!
This is a class for verticies to be used in meshes.
*/
class Vertex
{
public:
	//! Constructor
	Vertex(const glm::vec3& position,
		const glm::vec3& colour = glm::vec3(1, 1, 1),
		const glm::vec2& textureCoord = glm::vec2(0, 0),
		const glm::vec3& normal = glm::vec3(0, 0, 0));

	//! Vertex xyz coordinates
	glm::vec3 vertexPosition;
	//! Vertex colour
	glm::vec3 vertexColour;
	//! Vertex UV coordinates
	glm::vec2 vertexTextureCoord;
	//! Vertex normal location
	glm::vec3 vertexNormal;
};