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

private:
	//std::vector<Node> childNodes;
};
