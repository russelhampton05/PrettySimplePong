#pragma once
#include "ICommand.h"
class MoveLDCommand : public ICommand
{
public:
	MoveLDCommand();
	~MoveLDCommand();

	void execute(IMovable&);
};

