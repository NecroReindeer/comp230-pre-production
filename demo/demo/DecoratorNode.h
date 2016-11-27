#pragma once
#include "Node.h"
class DecoratorNode :
	public Node
{ //! Decorator node
public:
	//! Constructor
	DecoratorNode();
	//! Destructor
	~DecoratorNode();


	//! Inverts a NodeState
	Node::NodeStates invertState(Node::NodeStates currentState);
	//! Inverts a bool
	bool invertBool(bool state);


};

