#include "stdafx.h"
#include "BranchManager.h"


BranchManager::BranchManager(Falcon* theFalcon)
{
	falcon = theFalcon;
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
	if (falcon->getHealth() == 0)
	{
		currentNode = std::make_shared<DeadBranch>();
		std::cout << "changed branch " << std::endl;
	}
}

void BranchManager::update()
{
	currentNode->update(getCompanionHealth());

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
	return falcon->getHealth();
}
