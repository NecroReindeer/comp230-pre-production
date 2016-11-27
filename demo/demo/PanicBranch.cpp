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
	inverter.invertState(hooded.checkForHood(companion));
	
	return Node::NodeStates::Success;

}