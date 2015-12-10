#pragma once
#include "ICommand.h"
class IMovable;
class MoveRightCommand : public ICommand
{
public:
	MoveRightCommand();
	~MoveRightCommand();

	void execute(IMovable&);
};

