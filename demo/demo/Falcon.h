#pragma once
#include"Companion.h"

class Falcon : public Companion
{
	//! Main class for the Falcon
public:
	//! Constructor
	Falcon();
	//! Destructor
	~Falcon();

	void update();

private:
	//! int for the falcon's current location
	float x, y, z;
	float health = 100;
};

