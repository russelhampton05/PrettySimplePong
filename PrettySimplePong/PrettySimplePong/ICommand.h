#pragma once
class IUpdatable;
class ICommand
{
public:
	ICommand();
	~ICommand();
	virtual void execute(IUpdatable&) = 0;
};

