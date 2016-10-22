#include "stdafx.h"
#include "CompositeNode.h"


CompositeNode::CompositeNode()
{
}


CompositeNode::~CompositeNode()
{
}


Node::NodeStates CompositeNode::update()
{
	return Node::NodeStates::Running;
}
