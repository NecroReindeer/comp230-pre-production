#include "stdafx.h"
#include "DeadBranch.h"


DeadBranch::DeadBranch()
{
}


DeadBranch::~DeadBranch()
{
}

Node::NodeStates DeadBranch::update(int animalHealth)
{
	std::cout << "dead" << std::endl;
	return Node::NodeStates::Running;
}

