#include "stdafx.h"
#include "LeafNode.h"


LeafNode::LeafNode()
{
}


LeafNode::~LeafNode()
{
}

Node::NodeStates LeafNode::update(Companion* companion)
{
	return Node::NodeStates::Success;
}

bool LeafNode::checkHealth(float currentHealth, float healthThreshold)
{
	if (currentHealth <= healthThreshold)
		return true;
	else
		return false;
}

bool LeafNode::checkForCommand(Companion* companion)
{
	// TODO: add command bool to Companion
	//return companion.commandPresent;
	return false;
}
