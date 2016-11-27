#pragma once
#include "Companion.h"
#include"DeadBranch.h"
#include"IdleBranch.h"

class BranchManager
{ //! Class that manages the companions behaviour by managing the different branches 
	//TODO : replace with selector
public:
	//! Constructor
	BranchManager();
	//! Constructor where companion is passed in
	BranchManager(Companion* theCompanion);
	//! Destructor
	~BranchManager();

	// Pointer to the node that is running
	std::shared_ptr<CompositeNode> currentNode;

	IdleBranch idle;
	DeadBranch deadBranch;
	

	//! Pointer to companion animal
	Companion* companion;

	//! changeBranch is called when the current branch fails of succedes
	void changeBranch();

	//! Updates the current branch
	void update();
	//! returns the companions current health
	int getCompanionHealth();

	//! Checks the current health against a given number and returns a bool
	bool checkHealth(int healthThreshold);
	
};

