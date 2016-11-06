#include "stdafx.h"
#include "Falcon.h"


Falcon::Falcon()
{
}


Falcon::~Falcon()
{
}

void Falcon::update()
{
	if (health <= 0)
		health = 0;
}
