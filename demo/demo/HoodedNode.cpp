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
	if (companion->isHooded)
		return Node::NodeStates::Success;
	else if (!companion->isHooded)
		return Node::NodeStates::Failure;
}
