#pragma once
#include "ICommand.h"
class IMovable;
class MoveDownCommand : public ICommand
{
public:
	MoveDownCommand();
	~MoveDownCommand();

	void execute(IMovable&);
};

