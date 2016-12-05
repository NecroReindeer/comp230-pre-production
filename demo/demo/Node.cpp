#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}

Node::~Node()
{
}


Node::NodeStates Node::update()
{
	std::cout << "called node update " << std::endl;
	return Node::NodeStates::Running;
}
