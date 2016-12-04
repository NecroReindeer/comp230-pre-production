#include "stdafx.h"
#include "SequenceNode.h"


SequenceNode::SequenceNode()
{
}


SequenceNode::~SequenceNode()
{
}

Node::NodeStates SequenceNode::update(Companion* companion)
{
	for (int i = 0; i < childNodes.size(); i++)
	{
		childNodes[i]->update();
		if (childNodes[i]->nodeState == Node::NodeStates::Failure)
			return childNodes[i]->nodeState;
	}
	return Node::NodeStates::Success;
}

