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
	std::cout << "idle update" << std::endl;

	return Node::NodeStates::Failure;
}
