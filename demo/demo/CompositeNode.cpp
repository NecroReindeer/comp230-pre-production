#include "stdafx.h"
#include "CompositeNode.h"


CompositeNode::CompositeNode()
{
}


CompositeNode::~CompositeNode()
{
}


Node::NodeStates CompositeNode::update(Companion* companion)
{
	std::cout << "called composite update " << std::endl;
	return Node::NodeStates::Running;
}
