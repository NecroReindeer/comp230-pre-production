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

	Node::NodeStates update();

	bool checkHealth(int currentHealth, int healthThreshold);
};

