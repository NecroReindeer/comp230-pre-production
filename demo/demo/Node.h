#pragma once
#include"Companion.h"
//! Abstract class for all Node types to inherit from.
class Node
{
public:
	//! Constructor
	Node();
	//! Destructor
	~Node();

	//! enum of possible states for nodes
	enum class NodeStates { Success, Failure, Running };
	//! The state the Node is currently in
	NodeStates nodeState;
	
	//! Updates nodeState
	virtual Node::NodeStates update();
};
