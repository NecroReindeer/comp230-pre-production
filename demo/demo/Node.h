#pragma once

class Falcon;
//! Abstract node that other node types will inherit from
class Node
{
public:
	//! Constructor
	Node();
	//! Destructor
	~Node();

	//! Possible states for nodes to return to their parent
	enum class NodeStates { Success, Failure, Running };
	NodeStates nodeState;
	
	//! Virtual update function
	virtual Node::NodeStates update() =0;
};

