#pragma once
#include "ICommand.h"
class MoveRDCommand : public ICommand
{
public:
	MoveRDCommand();
	~MoveRDCommand();

	void execute(IMovable&);
};

