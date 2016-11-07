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
	int x, y, z;
	int health = 100;
};

