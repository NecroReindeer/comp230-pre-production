#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
class IdleRestingNode :
	public CompositeNode  //TODO Change to sequence or selector
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

