#pragma once
#include"Mesh.h"
#include"Texture.h"
//! Class for creating planes.
/*!
This is a class for creating and handling planes in the game.
It contains and mesh and a texture.
*/
class Plane
{
public:
	//! Constructor
	Plane();
	//! Alternate constructor
	Plane(int floorYPosition, int initialFloorSize, const std::string& floorTexture);
	//! Destructor
	~Plane();

	//! Floor texture
	Texture texture;
	//! Floor mesh
	Mesh mesh;

	//! returns floor Y value
	float getY() { return y; }
	//! returns floorSize
	float getFloorSize() { return floorSize; }

private:
	//! Plane Y position
	const float y = -2;
	//! planeSize for rendering
	const float floorSize = 10;
};

