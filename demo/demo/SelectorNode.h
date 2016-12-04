#pragma once
#include "CompositeNode.h"
//! Abstract class for selector nodes.
/*!
This is a class for a node where a single child node has succeed for the node to succeed
*/
class SelectorNode :
	public CompositeNode
{
public:
	//! Constructor
	SelectorNode();
	//! Destructor
	~SelectorNode();

	//! Checks to find one successful child
	Node::NodeStates update(Companion* companion);
};

