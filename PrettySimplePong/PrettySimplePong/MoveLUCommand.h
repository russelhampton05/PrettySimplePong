#pragma once
#include "ICommand.h"
class MoveLUCommand : public ICommand
{
public:
	MoveLUCommand();
	~MoveLUCommand();

	void execute(IMovable&);
};

