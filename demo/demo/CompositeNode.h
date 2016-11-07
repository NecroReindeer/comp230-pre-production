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
	virtual Node::NodeStates update(int animalHealth);

private:
	//std::vector<Node> childNodes;
};

