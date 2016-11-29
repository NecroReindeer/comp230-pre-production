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

	if (companion->isPanicing == true && companion->getHealth() > 99)
	{
		return nodeState = Node::NodeStates::Success;
	}
	else if (companion->isPanicing == false  && companion->getHealth() < 1)
	{
		return nodeState = Node::NodeStates::Failure;
	}
	else if (companion->isPanicing == true)
	{
		return nodeState = Node::NodeStates::Running;
	}

}