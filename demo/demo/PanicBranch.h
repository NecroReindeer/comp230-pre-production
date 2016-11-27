#pragma once
#include"CompositeNode.h"
class PanicBranch :
	public CompositeNode
{
public:
	PanicBranch();
	~PanicBranch();

	Node::NodeStates update(Companion* companion);
};

