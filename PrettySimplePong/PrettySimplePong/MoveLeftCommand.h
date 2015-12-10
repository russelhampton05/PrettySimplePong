#pragma once
#include "ICommand.h"
class IMovable;
class MoveLeftCommand : public ICommand
{
public:
	MoveLeftCommand();
	~MoveLeftCommand();


	void execute(IMovable&);

};

