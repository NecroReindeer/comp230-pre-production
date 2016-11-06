#pragma once
#include "Falcon.h"
#include"DeadBranch.h"
#include"IdleBranch.h"

class BranchManager
{
public:
	//! Constructor
	BranchManager();
	BranchManager(Falcon* theFalcon);
	~BranchManager();

	// Pointer to the node that is running
	std::shared_ptr<CompositeNode> currentNode;

	IdleBranch idle;

	//!Pointer to falcon
	Falcon* falcon;

	void changeBranch();

	void update();
	//! returns the companions current health
	int getCompanionHealth();

	//! Checks the current health against a given number and returns a bool
	bool checkHealth(int healthThreshold);
	
};

