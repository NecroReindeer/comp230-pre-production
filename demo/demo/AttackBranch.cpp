#include "stdafx.h"
#include "AttackBranch.h"


AttackBranch::AttackBranch()
{
}


AttackBranch::~AttackBranch()
{
}

Node::NodeStates AttackBranch::update(Companion* companion)
{
	std::cout << "attack update" << std::endl;  // for testing

	if (!enemyPresent.checkForEnemy(companion))
	{
		nodeState = Node::NodeStates::Failure;
		return nodeState;
	}
	if (pathToEnemy.nodeState == Node::NodeStates::Failure)
	{
		nodeState = Node::NodeStates::Failure;
		return nodeState;
	}
	if (checkHealth.checkHealth(companion->getHealth(), companion->attackHealthThreshold))
	{
		nodeState = Node::NodeStates::Failure;
		return nodeState;
	}
		
	
	//attackEnemy.update(companion);
	return Node::NodeStates::Running;
}
