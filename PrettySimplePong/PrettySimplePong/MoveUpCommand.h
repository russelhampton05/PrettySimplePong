#pragma once
#include "ICommand.h"
class IMovable;
class MoveUpCommand : public ICommand
{

public:

	MoveUpCommand();
	~MoveUpCommand();

	void execute(IMovable&);
};

