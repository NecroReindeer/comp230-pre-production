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
	for (int i = 0; i < childNodes.size(); i++)
	{
		if (childNodes[i].update(animalHealth) == Node::NodeStates::Failure)
			return Node::NodeStates::Failure;
		
		
	}
	return Node::NodeStates::Running;
}
