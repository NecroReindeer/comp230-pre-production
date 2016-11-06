#include "stdafx.h"
#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}

Node::NodeStates Node::update(int animalHealth)
{
	return Node::NodeStates::Running;
}