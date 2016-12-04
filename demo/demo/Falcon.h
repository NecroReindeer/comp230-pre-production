#pragma once
#include"Companion.h"
//! Falcon companion AI class
class Falcon : public Companion
{
public:
	//! Constructor
	Falcon();
	//! Destructor
	~Falcon();

	//! Updates falcon
	/*!
		Updates Falcon position/health/behaviour branch
	*/
	void update();

private:
	//! int for the falcon's X,Y,Z coordinates
	float x, y, z;
	//! falcon's health level
	float health = 100;
};

