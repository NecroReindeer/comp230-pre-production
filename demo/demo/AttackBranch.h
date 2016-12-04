#pragma once
#include"SequenceNode.h"
#include"SelectorNode.h"
#include"LeafNode.h"
class AttackBranch:
	public SequenceNode
{
public:
	//! Constructor
	AttackBranch();
	//! Destructor
	~AttackBranch();

	Node::NodeStates update(Companion* companion);

	LeafNode enemyPresent;
	LeafNode pathToEnemy;
	SelectorNode attackEnemy;
};

