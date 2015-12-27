#pragma once
#include "ICommand.h"
class MoveRUCommand : public ICommand
{
public:
	MoveRUCommand();
	~MoveRUCommand();
	void execute(IMovable&);
};

