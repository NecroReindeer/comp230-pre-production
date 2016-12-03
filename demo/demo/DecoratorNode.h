#pragma once
#include "Node.h"
//! Class for a decarator node.
class DecoratorNode :
	public Node
{ //! Decorator node
public:
	//! Constructor
	DecoratorNode();
	//! Destructor
	~DecoratorNode();

	//! Inverts a NodeState
	/*
		returns a nodeState that is the inverse of the one passed in
	*/
	Node::NodeStates invertState(Node::NodeStates currentState);
	//! Inverts a bool
	/*
		returns a bool that is the inverse of the one passed in
	*/
	bool invertBool(bool state);


};

