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
	virtual float getX() { return x; }
	//! returns int of value y
	virtual float getY() { return y; }
	//! returns int of value z
	virtual float getZ() { return z; }
	//! returns int of value health
	virtual float getHealth() { return health; }


	//! sets value of x
	virtual float setX(int newX) { return x = newX; }
	//! sets value of y
	virtual float setY(int newY) { return y = newY; }
	//! sets value of z
	virtual float setZ(int newZ) { return z = newZ; }
	//! sets value of health
	virtual float setHealth(int newHealth) { return health = newHealth; }

	bool isHooded = false;
private:
	//! int for the companions's current location
	float x, y, z;
	float health = 100;
};

