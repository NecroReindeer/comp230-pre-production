#pragma once
#include "Node.h"
class DecoratorNode :
	public Node
{
public:
	//! Constructor
	DecoratorNode();
	//! Destructor
	~DecoratorNode();


	//! 
	void invert(Node::NodeStates currentState);


};

