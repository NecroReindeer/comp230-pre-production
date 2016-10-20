#include "stdafx.h"
#include "DecoratorNode.h"


DecoratorNode::DecoratorNode()
{
}


DecoratorNode::~DecoratorNode()
{
}

// Inverts the input if the input is failure or success
void DecoratorNode::invert(Node::NodeStates currentState)
{
	if (currentState == Node::NodeStates::Failure)
	{
		currentState == Node::NodeStates::Success;
	}
	else if (currentState == Node::NodeStates::Success)
	{
		currentState == Node::NodeStates::Failure;
	}
}
