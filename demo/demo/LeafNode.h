#pragma once
#include "Node.h"
//! Class for a leaf node.
class LeafNode :
	public Node
{
public:
	//! Constructor
	LeafNode();
	//! Destructor
	~LeafNode();

	//! Updates the node and returns a NodeStates
	Node::NodeStates update(Companion* companion);

	//! checks whether the health is above a certain value
	bool checkHealth(float currentHealth, float healthThreshold);
	//! checks for player input
	bool checkForCommand(Companion* companion);
	//! returns bool that indicates whether there's an enemy near the falcon
	bool checkForEnemy(Companion* companion);
};

