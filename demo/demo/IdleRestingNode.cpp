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
	if ((lowHealth.checkHealth(companion->getHealth(), 0)))
	{ // if health reaches 0 Idle branch fails
		nodeState = Node::NodeStates::Failure;
	}
	else if ((lowHealth.checkHealth(companion->getHealth(), 20)))
	{  // If health is below 20 healing Idle
		nodeState = Node::NodeStates::Running;
	}
	else if (resting.checkForCommand(companion))
	{
		nodeState = Node::NodeStates::Success;
	}
	else if (resting.checkForEnemy(companion))
	{
		nodeState = Node::NodeStates::Success;
	}

	else 
	{
		nodeState = Node::NodeStates::Running;
	}
	return nodeState;
}
