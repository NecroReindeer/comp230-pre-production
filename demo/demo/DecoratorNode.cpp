#include "stdafx.h"
#include "DecoratorNode.h"


DecoratorNode::DecoratorNode()
{
}


DecoratorNode::~DecoratorNode()
{
}

// Inverts the input if the input is failure or success
Node::NodeStates DecoratorNode::invertState(Node::NodeStates currentState)
{
	if (currentState == Node::NodeStates::Failure)
	{
		return Node::NodeStates::Success;
	}
	else if (currentState == Node::NodeStates::Success)
	{
		return Node::NodeStates::Failure;
	}
	else 
		return Node::NodeStates::Failure;
	// add error
}

bool DecoratorNode::invertBool(bool state)
{
	if (state == false)
	{
		return true;
	}
	else if (state == true)
	{
		return false;
	}
}
