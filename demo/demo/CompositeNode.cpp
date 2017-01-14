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
	for (int i = 0; i < childNodes.size(); i++)
	{
		childNodes[i]->update();

		if (childNodes[i]->nodeState == Node::NodeStates::Success)
			return Node::NodeStates::Success;
		else if (childNodes[i]->nodeState == Node::NodeStates::Failure)
			return Node::NodeStates::Failure;

	}
	return Node::NodeStates::Running;
}

void CompositeNode::addChild(Node* node)
{
	childNodes.push_back(node);
}

bool CompositeNode::nodeHasChild()
{
	if (childNodes.empty())
		return true;
}
