#include "stdafx.h"
#include "PanicBranch.h"


PanicBranch::PanicBranch()
{
}


PanicBranch::~PanicBranch()
{
}

Node::NodeStates PanicBranch::update(Companion* companion)
{
	std::cout << "panic update" << std::endl;  // for testing
	if (inverter.invertState(hooded.checkForHood(companion)) == Node::NodeStates::Failure)
	{
		return nodeState = Node::NodeStates::Success;
	}
	if (inverter.invertState(hooded.checkForHood(companion)) == Node::NodeStates::Success  )
	{
		return nodeState = Node::NodeStates::Failure;
	}
}