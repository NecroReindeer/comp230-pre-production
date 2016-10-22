#include "stdafx.h"
#include "DeadBranch.h"


DeadBranch::DeadBranch()
{
}


DeadBranch::~DeadBranch()
{
}

Node::NodeStates DeadBranch::update(Falcon* falcon)
{
	if (dead.checkHealth(falcon->getHealth(), 0))
	{
		dead.nodeState == Node::NodeStates::Running;
		return Node::NodeStates::Running;
	}
	else
	{
		dead.nodeState == Node::NodeStates::Failure;
		return Node::NodeStates::Failure;
	}
}

