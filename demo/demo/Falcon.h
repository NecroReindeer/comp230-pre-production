#pragma once
class Falcon : public Falcon
{
	//! Main class for the Falcon
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
	//! returns int of value health
	int getHealth() { return health; }


	//! sets value of x
	int setX(int newX) { return x = newX; }
	//! sets value of y
	int setY(int newY) { return y = newY; }
	//! sets value of z
	int setZ(int newZ) { return z = newZ; }
	//! sets value of health
	int setHealth(int newHealth) { return health = newHealth; }

	//! updates falcons location and branch state
	void update();

	// currentBranch/Node ?


private:
	//! int for the falcon's current location
	int x, y, z;
	int health = 100;
};

