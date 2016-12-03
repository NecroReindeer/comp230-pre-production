#include "stdafx.h"
#include "SelectorNode.h"


SelectorNode::SelectorNode()
{
}


SelectorNode::~SelectorNode()
{
}

Node::NodeStates SelectorNode::update(Companion* companion)
{
	for (int i = 0; i < childNodes.size(); i++)
	{
		childNodes[i].update();
		if (childNodes[i].nodeState == Node::NodeStates::Success)
			return childNodes[i].nodeState;
	}
	return Node::NodeStates::Failure;
}
