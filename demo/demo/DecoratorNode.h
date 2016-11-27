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


	//! Inverts the result: makes true = false
	Node::NodeStates invertState(Node::NodeStates currentState);

	bool invertBool(bool state);


};

