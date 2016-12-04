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
	if (enemyPresent.nodeState == Node::NodeStates::Failure)
		return Node::NodeStates::Failure;
	if (pathToEnemy.nodeState == Node::NodeStates::Failure)
		return Node::NodeStates::Failure;
	
	attackEnemy.update(companion);
	return attackEnemy.nodeState;
}
