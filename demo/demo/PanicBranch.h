#pragma once
#include"CompositeNode.h"
#include "HoodedNode.h"
#include "DecoratorNode.h"
class PanicBranch :
	public CompositeNode
{
public:
	PanicBranch();
	~PanicBranch();

	Node::NodeStates update(Companion* companion);

	DecoratorNode inverter;
	HoodedNode hooded;
};

