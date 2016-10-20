#pragma once
//! Abstract node that other node types will inherit from
class Node
{
public:
	Node();
	~Node();

	enum class NodeStates { Success, Failure, Running };
	NodeStates nodeState;
	
	virtual void update() = 0;
};

