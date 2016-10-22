#pragma once
#include "Node.h"
#include "Falcon.h"

class LeafNode :
	public Node
{
public:
	//! Constructor
	LeafNode();
	//! Destructor
	~LeafNode();

	void update(Falcon falcon);

	bool checkHealth(int currentHealth, int healthThreshold);
};

