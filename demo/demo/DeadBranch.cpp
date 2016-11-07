#include "stdafx.h"
#include "DeadBranch.h"


DeadBranch::DeadBranch()
{
}


DeadBranch::~DeadBranch()
{
}

Node::NodeStates DeadBranch::update(int animalHealth)
{
	std::cout << "dead update" << std::endl;

	if (deadNode.checkHealth(animalHealth, 0))
	{
		nodeState = Node::NodeStates::Running;
		return nodeState;
	}
		
	else
		// Should never fail as falcon can not leave dead branch
		return Node::NodeStates::Failure;
}

