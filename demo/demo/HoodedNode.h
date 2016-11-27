#pragma once
#include "LeafNode.h"
class HoodedNode :
	public LeafNode
{
public:
	//! Constructor
	HoodedNode();
	//! Destructor
	~HoodedNode();

	Node::NodeStates checkForHood(Companion* companion);
};

