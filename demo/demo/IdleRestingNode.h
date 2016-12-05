#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
//! Class for resting node

class IdleRestingNode :
	public CompositeNode
{
public:
	//! Constructor
	IdleRestingNode();
	//! Destructor
	~IdleRestingNode();

	//! Updates the node and returns a NodeState
	Node::NodeStates update(Companion* companion);

	//! Checks for low health
	LeafNode lowHealth;
	//! Check if resting
	LeafNode resting;
};

