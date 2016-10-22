#include "stdafx.h"
#include "LeafNode.h"


LeafNode::LeafNode()
{
}


LeafNode::~LeafNode()
{
}

bool LeafNode::checkHealth(int currentHealth, int healthThreshold)
{
	if (currentHealth <= healthThreshold)
		return true;
	else
		return false;
}

Node::NodeStates LeafNode::update()
{
	return Node::NodeStates::Running;
}