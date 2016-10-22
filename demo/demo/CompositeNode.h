#pragma once
#include "Node.h"
class CompositeNode :
	public Node
{
public:
	//! Constructor
	CompositeNode();
	//! Destructor
	~CompositeNode();

	//! Sequence
	// All condition must be true
	void sequence();

	//! Selector
	// Only one needs to be chosen
	void selector();

	Node::NodeStates update();
};

