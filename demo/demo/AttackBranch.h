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

	//! Updates branch
	Node::NodeStates update(Companion* companion);

	//! Child node to check if enemies are near
	LeafNode enemyPresent;
	//! Child node to check if player can reach enemies 
	LeafNode pathToEnemy;
	//! Child node to check if companion has enough health to attack
	LeafNode checkHealth;
	//! Child node that will decide how to attack
	SelectorNode attackEnemy;
};

