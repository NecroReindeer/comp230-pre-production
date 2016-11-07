#pragma once


class Node
{//! Abstract node that other node types will inherit from
public:
	//! Constructor
	Node();
	//! Destructor
	~Node();

	//! Possible states for nodes to return to their parent
	enum class NodeStates { Success, Failure, Running };
	//! The state the Node is currently in
	NodeStates nodeState;
};
