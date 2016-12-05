#pragma once
#include "Companion.h"
#include"DeadBranch.h"
#include"IdleBranch.h"
#include"InjuredBranch.h"
#include"AttackBranch.h"
//! Class for Branch Manager.
/*!
This is a class for handling the companions current branch
TODO : replace with selector
*/
class BranchManager
{ 
public:
	//! Constructor
	BranchManager();
	//! Constructor where companion is passed in
	BranchManager(Companion* theCompanion);
	//! Destructor
	~BranchManager();

	// Pointer to the node that is running
	std::shared_ptr<CompositeNode> currentNode;

	//! Instance of IdleBranch
	IdleBranch idle;
	//! Instance of DeadBranch
	DeadBranch deadBranch;
	//! Instance of InjuredBranch
	InjuredBranch injuredBranch;
	//! Instance of AttackBranch
	AttackBranch attackBranch;
	

	//! Pointer to companion animal
	Companion* companion;

	//! changeBranch is called when the current branch fails of succedes
	void changeBranch();

	//! Updates the current branch
	void update();	
};

