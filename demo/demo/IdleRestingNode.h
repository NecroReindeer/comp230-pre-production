#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
class IdleRestingNode :
	public CompositeNode
{
public:
	IdleRestingNode();
	~IdleRestingNode();

	Node::NodeStates update(Companion* companion);

	LeafNode lowHealth;
	LeafNode resting;
};

