#include "stdafx.h"
#include "DeadBranch.h"


DeadBranch::DeadBranch()
{
}


DeadBranch::~DeadBranch()
{
}

Node::NodeStates DeadBranch::update(Companion* companion)
{
	std::cout << "dead update" << std::endl;  // for testing

	if (deadNode.checkHealth(companion->getHealth(), 0))
		nodeState = Node::NodeStates::Running;
		
	else
		// Should never fail as falcon can not leave dead branch
		nodeState = Node::NodeStates::Failure;
	
	return nodeState;
}

