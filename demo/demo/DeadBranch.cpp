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
	std::cout << "dead branch" << std::endl;

	if (deadNode.checkHealth(animalHealth, 0))
		return Node::NodeStates::Running;
	else
		// Should never fail
		return Node::NodeStates::Failure;
}

