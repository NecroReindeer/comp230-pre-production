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
	if (companion->isPanicking)
		return Node::NodeStates::Success;
	else if (!companion->isPanicking)
		return Node::NodeStates::Failure;
}
