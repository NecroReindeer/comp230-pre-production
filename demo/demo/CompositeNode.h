#pragma once
#include "Node.h"
class CompositeNode :
	public Node
{
public:
	//! Constructor
	CompositeNode();
	//! Destructor
	~CompositeNode();

	virtual Node::NodeStates update(int animalHealth);

private:
	//std::vector<Node> childNodes;
};

