#pragma once
#include "Node.h"
class CompositeNode :
	public Node
{ //! Abstract class for composite nodes to inherit from
public:
	//! Constructor
	CompositeNode();
	//! Destructor
	~CompositeNode();

	//! Updates the Node
	virtual Node::NodeStates update(Companion* companion);

	//! adds a node to the childNodes vector
	virtual void addChild(Node* node);
	//! Checks to see if childNodes is empty
	virtual bool nodeHasChild();
	//! Vector of child nodes
	std::vector<Node*> childNodes;
};

