#include "stdafx.h"
#include "LeafNode.h"


LeafNode::LeafNode()
{
}


LeafNode::~LeafNode()
{
}

Node::NodeStates LeafNode::update(int animalHealth)
{
	return Node::NodeStates::Success;
}

bool LeafNode::checkHealth(int currentHealth, int healthThreshold)
{
	if (currentHealth <= healthThreshold)
		return true;
	else
		return false;
}