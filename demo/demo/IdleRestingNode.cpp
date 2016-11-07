#include "stdafx.h"
#include "IdleRestingNode.h"


IdleRestingNode::IdleRestingNode()
{
}


IdleRestingNode::~IdleRestingNode()
{
}

Node::NodeStates IdleRestingNode::update(Companion* companion)
{
	if ((lowHealth.checkHealth(companion->getHealth(), 10)))
	{
		return Node::NodeStates::Failure;
	}
	else 
	{
		return Node::NodeStates::Running;
	}
}
