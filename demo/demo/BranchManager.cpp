#include "stdafx.h"
#include "BranchManager.h"


BranchManager::BranchManager(Companion* theCompanion)
{
	companion = theCompanion;
	currentNode = std::make_shared<IdleBranch>(idle);
}

BranchManager::BranchManager()
{
}

BranchManager::~BranchManager()
{
}

void BranchManager::changeBranch()
{
	if (companion->getHealth() == 0)
	{
		currentNode = std::make_shared<DeadBranch>();
		std::cout << "changed branch " << std::endl;  // for testing
	}
	else if (companion->getHealth() < 40 && companion->getHealth() > 0)
	{
		currentNode = std::make_shared<InjuredBranch>();
		std::cout << "changed branch " << std::endl;  // for testing
	}
}

void BranchManager::update()
{
	currentNode->update(companion);

	if (currentNode->nodeState == Node::NodeStates::Failure )
	{
		changeBranch();
	}
	else if (currentNode->nodeState == Node::NodeStates::Success)
	{
		changeBranch();
	}
}

int BranchManager::getCompanionHealth()
{
	return companion->getHealth();
}
