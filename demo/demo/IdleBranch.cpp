#include "stdafx.h"
#include "IdleBranch.h"


IdleBranch::IdleBranch()
{
}


IdleBranch::~IdleBranch()
{
}

Node::NodeStates IdleBranch::update(Companion* companion)
{
	std::cout << "idle update" << std::endl;  // for testing

	if (restingNode.nodeState == Node::NodeStates::Failure)
		return Node::NodeStates::Failure;
	
}
