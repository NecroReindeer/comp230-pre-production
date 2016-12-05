#pragma once
#include "Vertex.h"
//! Class for meshes.
/*!
This is a class for handling mesh creation and rendering
*/
class Mesh
{
public:
	//! Constructor
	Mesh();
	//! Destructor
	~Mesh();

	//! Creates a triangle
	void addTriangle(Vertex v1, Vertex v2, Vertex v3);
	//! Creates a triangle with a colour
	void addTriangle(Vertex v1, Vertex v2, Vertex v3, const glm::vec3& colour);
	//! adds triangle using glm::vec3 instead of vertex
	void addTriangle(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3,
		const glm::vec3& colour,
		const glm::vec2& t1, const glm::vec2& t2, const glm::vec2& t3);
	//! Creates a square
	void addSquare(Vertex v1, Vertex v2, Vertex v3, Vertex v4, const glm::vec3& colour);
	//! Creates a square using glm::vec3
	void addSquare(const glm::vec3& a, const glm::vec3& b,
		const glm::vec3& c, const glm::vec3& d, const glm::vec3& colour,
		float u1, float u2, float v1, float v2);
	//! Creates a sphere
	void addSphere(float radius, int quality, const glm::vec3& colour);
	//! Creates a vertex
	void addVertex(const Vertex& vertex);
	//! Creates a sphere vertex
	/*!
		returns a vertex
	*/
	Vertex createSphereVertex(float radius, float longitude, float latitude, const glm::vec3& colour);

	//! Creates all the buffers needs for a mesh
	void createBuffers();
	//! Draws the mesh
	void draw();

	//! Vectors of unsinged ints containing vertexIndices, uvIndices, normalIndices
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;

	//!  vector of vec3s used in buffers
	std::vector<glm::vec3> m_vertexPositions, m_vertexColours, m_vertexNormals;
	std::vector<glm::vec2> m_vertexUVs;
	//! Gluints for buffers
	GLuint m_positionBuffer = 0, m_colourBuffer = 0, m_uvBuffer = 0, m_normalBuffer = 0;

	
};