#include "stdafx.h"
#include "IdleRestingNode.h"


IdleRestingNode::IdleRestingNode()
{
}


IdleRestingNode::~IdleRestingNode()
{
}

Node::NodeStates IdleRestingNode::update(int animalHealth)
{
	if ((lowHealth.checkHealth(animalHealth, 10)))
	{
		return Node::NodeStates::Failure;
	}
	else 
	{
		return Node::NodeStates::Running;
	}
}
