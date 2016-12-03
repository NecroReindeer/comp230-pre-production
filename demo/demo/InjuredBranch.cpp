#include "stdafx.h"
#include "InjuredBranch.h"


InjuredBranch::InjuredBranch()
{
}


InjuredBranch::~InjuredBranch()
{
}

Node::NodeStates InjuredBranch::update(Companion* companion)
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