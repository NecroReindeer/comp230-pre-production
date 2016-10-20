#pragma once
//! Abstract node that other node types will inherit from
class Node
{
public:
	Node();
	~Node();

	enum class NodeState { Success, Failure, Running };
	
	virtual void update() = 0;
};

