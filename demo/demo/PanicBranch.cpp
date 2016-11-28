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

	if (companion->isHooded == true && companion->getHealth() > 99)
	{
		return nodeState = Node::NodeStates::Success;
	}
	else if (companion->isHooded == false  && companion->getHealth() < 1)
	{
		return nodeState = Node::NodeStates::Failure;
	}
	else if (companion->isHooded == true)
	{
		return nodeState = Node::NodeStates::Running;
	}

}