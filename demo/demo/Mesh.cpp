#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
	if (m_positionBuffer != 0)
		glDeleteBuffers(1, &m_positionBuffer);

	if (m_colourBuffer != 0)
		glDeleteBuffers(1, &m_colourBuffer);

	if (m_uvBuffer != 0)
		glDeleteBuffers(1, &m_uvBuffer);

	if (m_normalBuffer != 0)
		glDeleteBuffers(1, &m_normalBuffer);
}

void Mesh::addTriangle(Vertex v1, Vertex v2, Vertex v3, const glm::vec3& colour)
{
	glm::vec3 normal = glm::cross(v2.vertexPosition - v1.vertexPosition, v3.vertexPosition - v1.vertexPosition);
	normal = glm::normalize(normal);

	Vertex vertices[] = { v1,v2,v3 };

	for (int i = 0; i < 3; i++)
	{
		vertices[i].vertexNormal = normal;
		vertices[i].vertexColour = colour;
		addVertex(vertices[i]);
	}
}

void Mesh::addTriangle(Vertex v1, Vertex v2, Vertex v3)
{
	glm::vec3 normal = glm::cross(v2.vertexPosition - v1.vertexPosition, v3.vertexPosition - v1.vertexPosition);
	normal = glm::normalize(normal);

	Vertex vertices[] = { v1,v2,v3 };

	for (int i = 0; i < 3; i++)
	{
		vertices[i].vertexNormal = normal;
		addVertex(vertices[i]);
	}

}

void Mesh::addSquare(Vertex v1, Vertex v2, Vertex v3, Vertex v4, const glm::vec3& colour)
{
	addTriangle(v1, v2, v3, colour);
	addTriangle(v1, v3, v4, colour);
}

void Mesh::addVertex(const Vertex& vertex)
{
	if (m_positionBuffer != 0)
	{
		throw std::exception("Cannot add vertices after createBuffers() has been called");
	}

	m_vertexPositions.push_back(vertex.vertexPosition);
	m_vertexColours.push_back(vertex.vertexColour);
	m_vertexUVs.push_back(vertex.vertexTextureCoord);
	m_vertexNormals.push_back(vertex.vertexNormal);
}

Vertex Mesh::createSphereVertex(float radius, float longitude, float latitude, const glm::vec3& colour)
{
	glm::vec3 unitPos(
		cos(latitude) * cos(longitude),
		sin(latitude),
		cos(latitude) * sin(longitude));

	glm::vec2 textureCoords(
		-longitude / glm::radians(360.0f),
		latitude / glm::radians(180.0f) + 0.5f);

	return Vertex(radius * unitPos,
		colour,
		textureCoords);
}

void Mesh::addSphere(float radius, int quality, const glm::vec3& colour)
{
	float angleStep = glm::radians(90.0f) / quality;

	std::vector<Vertex> lastRingPoints, ringPoints;

	// Top cap
	float latitude = angleStep * (quality - 1);
	for (int i = 0; i <= quality * 4; i++)
	{
		float longitude = i * angleStep;
		ringPoints.push_back(createSphereVertex(radius, longitude, latitude, colour));
		if (ringPoints.size() > 1)
		{
			Vertex pole = createSphereVertex(radius, longitude - 0.5f*angleStep, glm::radians(90.0f), colour);
			addTriangle(pole, ringPoints[i], ringPoints[i - 1]);
		}
	}

	// Rings
	for (int j = quality - 2; j > -quality; j--)
	{
		lastRingPoints.clear();
		std::swap(lastRingPoints, ringPoints);

		float latitude = angleStep * j;
		for (int i = 0; i <= quality * 4; i++)
		{
			float longitude = i * angleStep;
			ringPoints.push_back(createSphereVertex(radius, longitude, latitude, colour));
			if (ringPoints.size() > 1)
			{
				addTriangle(lastRingPoints[i], ringPoints[i], ringPoints[i - 1]);
				addTriangle(lastRingPoints[i - 1], lastRingPoints[i], ringPoints[i - 1]);
			}
		}
	}

	// Bottom cap
	for (int i = 1; i < ringPoints.size(); i++)
	{
		Vertex pole = createSphereVertex(radius, (i - 0.5f)*angleStep, glm::radians(-90.0f), colour);
		addTriangle(pole, ringPoints[i - 1], ringPoints[i]);
	}
}



void Mesh::createBuffers()
{
	if (m_positionBuffer != 0)
	{
		throw std::exception("createBuffers() has already been called");
	}

	// Create and fill the position buffer
	glGenBuffers(1, &m_positionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_positionBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexPositions.size() * sizeof(glm::vec3), m_vertexPositions.data(), GL_STATIC_DRAW);

	// Create and fill the colour buffer
	glGenBuffers(1, &m_colourBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_colourBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexColours.size() * sizeof(glm::vec3), m_vertexColours.data(), GL_STATIC_DRAW);

	// Create and fill the texture coordinate buffer
	glGenBuffers(1, &m_uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexUVs.size() * sizeof(glm::vec2), m_vertexUVs.data(), GL_STATIC_DRAW);

	// Create and fill the normal buffer
	glGenBuffers(1, &m_normalBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_normalBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexNormals.size() * sizeof(glm::vec3), m_vertexNormals.data(), GL_STATIC_DRAW);
}

void Mesh::draw()
{
	if (m_positionBuffer == 0)
	{
		throw std::exception("createBuffers() must be called before draw()");
	}

	// Bind the position buffer to vertex attribute 0
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_positionBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	// Bind the colour buffer to vertex attribute 1
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_colourBuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	// Bind the texture coordinate buffer to vertex attribute 2
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, m_uvBuffer);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	// Bind the normal buffer to vertex attribute 3
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ARRAY_BUFFER, m_normalBuffer);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	glDrawArrays(GL_TRIANGLES, 0, m_vertexPositions.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
}



void Mesh::addTriangle(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3,
	const glm::vec3& colour,
	const glm::vec2& t1, const glm::vec2& t2, const glm::vec2& t3)
{
	if (m_positionBuffer != 0)
	{
		throw std::exception("Cannot add triangles after createBuffers() has been called");
	}

	// Add the vertex positions
	m_vertexPositions.push_back(p1);
	m_vertexPositions.push_back(p2);
	m_vertexPositions.push_back(p3);

	// Make all three vertices the same colour
	for (int i = 0; i < 3; i++)
		m_vertexColours.push_back(colour);

	// Add the texture coordinates
	m_vertexUVs.push_back(t1);
	m_vertexUVs.push_back(t2);
	m_vertexUVs.push_back(t3);
}

void Mesh::addSquare(const glm::vec3& a, const glm::vec3& b,
	const glm::vec3& c, const glm::vec3& d, const glm::vec3& colour,
	float u1, float u2, float v1, float v2)
{
	glm::vec2 ta(u1, v1);
	glm::vec2 tb(u1, v2);
	glm::vec2 tc(u2, v2);
	glm::vec2 td(u2, v1);

	addTriangle(a, b, d, colour, ta, tb, td);
	addTriangle(d, b, c, colour, td, tb, tc);
}