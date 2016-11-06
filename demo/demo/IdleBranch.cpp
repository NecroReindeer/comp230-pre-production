#include "stdafx.h"
#include "IdleBranch.h"


IdleBranch::IdleBranch()
{
}


IdleBranch::~IdleBranch()
{
}

Node::NodeStates IdleBranch::update(int animalHealth)
{
	std::cout << "idle " << std::endl;
	return Node::NodeStates::Failure;
}
