#pragma once
#include "CompositeNode.h"
#include "LeafNode.h"
class DeadBranch :
	public CompositeNode
{
public:
	DeadBranch();
	~DeadBranch();

	NodeStates nodeState = Node::NodeStates::Running;

	Node::NodeStates update(int animalHealth);
};

