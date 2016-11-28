#pragma once
#include"Mesh.h"
#include"Texture.h"

class Floor
{
public:
	//! Constructor
	Floor();
	//! Alternate constructor
	Floor(int floorYPosition, int initialFloorSize, const std::string& floorTexture);
	//! Destructor
	~Floor();

	//! Floor texture
	Texture texture;
	//! Floor mesh
	Mesh mesh;

	//! returns floor Y value
	float getY() { return y; }
	//! returns floorSize
	float getFloorSize() { return floorSize; }

private:
	//! Floor Y position
	const float y = -2;
	//! floorSize for rendering
	const float floorSize = 10;
};

