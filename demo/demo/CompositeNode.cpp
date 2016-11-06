#include "stdafx.h"
#include "CompositeNode.h"


CompositeNode::CompositeNode()
{
}


CompositeNode::~CompositeNode()
{
}


Node::NodeStates CompositeNode::update(int animalHealth)
{
	std::cout << "called composite update " << std::endl;
	return Node::NodeStates::Success;
}
