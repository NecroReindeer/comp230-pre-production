#pragma once
#include "CompositeNode.h"
#include "LeafNode.h"
class DeadBranch :
	public CompositeNode
{
public:
	DeadBranch();
	~DeadBranch();


	Node::NodeStates update(Falcon* falcon);
	LeafNode dead;
};

