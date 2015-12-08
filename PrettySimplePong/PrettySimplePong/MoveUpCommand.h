#pragma once
#include "ICommand.h"
class MoveUpCommand : public ICommand
{

public:

	MoveUpCommand();
	~MoveUpCommand();

	void execute(IUpdatable&);
};

