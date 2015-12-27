#pragma once
#include "ICommand.h"
class IMovable;

class NoCommand : public ICommand
{
public:
	NoCommand();
	~NoCommand();
	void execute(IMovable&);
};

