#pragma once
class IMovable;
class ICommand
{
public:
	ICommand();
	~ICommand();
	virtual void execute(IMovable&) = 0;
};

