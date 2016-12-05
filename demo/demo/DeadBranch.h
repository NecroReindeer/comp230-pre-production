#pragma once
#include "CompositeNode.h"
#include "LeafNode.h"

class DeadBranch :
	public CompositeNode
	//! DeadBranch for when the companion is dead
{
public:
	//! Cosntructor
	DeadBranch();
	//! Destructor
	~DeadBranch();

	//! Current state of the branch
	NodeStates nodeState = Node::NodeStates::Running;
	//! Updates branch to check for Node changes
	Node::NodeStates update(Companion* companion);

	//! Child leaf node that returns whether the falcon is dead or not
	LeafNode deadNode;
};

