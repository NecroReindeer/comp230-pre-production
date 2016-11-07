#pragma once
class Companion
	//! Abstract class for companion animals to inherit from
{
public:
	//! Constructor
	Companion();
	//! Destructor
	~Companion();

	//! updates function that updates companions
	virtual void update();

	//! returns int of value x
	virtual int getX() { return x; }
	//! returns int of value y
	virtual int getY() { return y; }
	//! returns int of value z
	virtual int getZ() { return z; }
	//! returns int of value health
	virtual int getHealth() { return health; }


	//! sets value of x
	virtual int setX(int newX) { return x = newX; }
	//! sets value of y
	virtual int setY(int newY) { return y = newY; }
	//! sets value of z
	virtual int setZ(int newZ) { return z = newZ; }
	//! sets value of health
	virtual int setHealth(int newHealth) { return health = newHealth; }

private:
	//! int for the companions's current location
	int x, y, z;
	int health = 100;
};

