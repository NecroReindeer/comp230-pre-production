#pragma once
#include "CompositeNode.h"
#include"LeafNode.h"
#include"IdleRestingNode.h"

class IdleBranch :
	public CompositeNode  // TODO: Change to Selector
	//! IdleBranch for when the companion is Idle
{
public:
	//! Constructor
	IdleBranch();
	//! Destructor
	~IdleBranch();

	//! Current state of the branch
	NodeStates nodeState = Node::NodeStates::Running;
	//! Updates branch to check for Node changes
	Node::NodeStates update(Companion* companion);
	
	//! Child node: Selector that choses node depending on whether falcon is injured
	IdleRestingNode restingNode;
};

