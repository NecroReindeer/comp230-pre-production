#pragma once
#include "CompositeNode.h"
//! Abstract class for sequence nodes.
/*!
This is a class for a node where all child nodes have to succeed for the node to succeed
*/
class SequenceNode :
	public CompositeNode
{
public:
	//! Constructor
	SequenceNode();
	//! Destructor
	~SequenceNode();

	Node::NodeStates update(Companion* companion);
};

