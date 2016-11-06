#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
class IdleBranch :
	public CompositeNode
{
public:
	//! Constructor
	IdleBranch();
	//! Destructor
	~IdleBranch();


	NodeStates nodeState = Node::NodeStates::Running;

	Node::NodeStates update(int animalHealth);
};

