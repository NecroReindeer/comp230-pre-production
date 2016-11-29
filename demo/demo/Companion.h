#pragma once
//! Abstract class for companion animals to inherit from
class Companion
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
	virtual float setX(float newX) { return x = newX; }
	//! sets value of y
	virtual float setY(float newY) { return y = newY; }
	//! sets value of z
	virtual float setZ(float newZ) { return z = newZ; }
	//! sets value of health
	virtual float setHealth(float newHealth) { return health = newHealth; }

	//! bool for whether the AI is panicing or not
	bool isPanicing = false;
private:
	//! int for the companions's current location
	float x, y, z;
	//! Companions health
	float health = 100;
};

