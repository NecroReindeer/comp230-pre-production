#pragma once
#include "Node.h"

class LeafNode :
	public Node
{
public:
	//! Constructor
	LeafNode();
	//! Destructor
	~LeafNode();

	Node::NodeStates update(int animalHealth);

	bool checkHealth(int currentHealth, int healthThreshold);
};

