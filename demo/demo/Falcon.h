#pragma once
class Falcon
{
public:
	//! Constructor
	Falcon();
	//! Destructor
	~Falcon();

	//! returns int of value x
	int getX() { return x; }
	//! returns int of value y
	int getY() { return y; }
	//! returns int of value z
	int getZ() { return z; }

	//! updates falcons location and state
	void update();


private:
	//! int for the falcon's current location
	int x, y, z;
};

