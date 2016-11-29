#include "stdafx.h"
#include "HoodedNode.h"


HoodedNode::HoodedNode()
{
}


HoodedNode::~HoodedNode()
{
}

Node::NodeStates HoodedNode::checkForHood(Companion* companion)
{
	if (companion->isPanicing)
		return Node::NodeStates::Success;
	else if (!companion->isPanicing)
		return Node::NodeStates::Failure;
}
