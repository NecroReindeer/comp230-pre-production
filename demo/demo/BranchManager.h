#pragma once
#include"CompositeNode.h"
#include "Falcon.h"
class BranchManager
{
public:
	BranchManager();
	~BranchManager();

	// Node that is running
	CompositeNode currentNode;

	//!Pointer to falcon
	Falcon* falcon;

	void update();
	

};

