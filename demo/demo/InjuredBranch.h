#pragma once
#include"SelectorNode.h"
#include "HoodedNode.h"
#include "DecoratorNode.h"
//! Class for PanicBranch.
/*!
This is a class for when the companion AI is injured.
*/
class InjuredBranch :
	public SelectorNode
{
public:
	InjuredBranch();
	~InjuredBranch();

	Node::NodeStates update(Companion* companion);

	DecoratorNode inverter;
	HoodedNode hooded;
};

