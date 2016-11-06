#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
class IdleRestingNode :
	public CompositeNode
{
public:
	IdleRestingNode();
	~IdleRestingNode();

	Node::NodeStates update(int animalHealth);

	LeafNode lowHealth;
};

