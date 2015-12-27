#pragma once
class ICommand;
class InputHandler
{
private:
	ICommand* moveDown;
	ICommand* moveUp;
	ICommand* moveLeft;
	ICommand* moveRight;
	ICommand* moveRightUp;
	ICommand* moveRightDown;
	ICommand* moveLeftUp;
	ICommand* moveLeftDown;
	ICommand* noCommand;
public:
	InputHandler();
	~InputHandler();
	void setMoveRight(ICommand* command)
	{
		moveRight = command;
	}
	void setNoCommand(ICommand* command)
	{
		noCommand = command;
	}
	void setMoveLeft(ICommand* command)
	{
		moveLeft = command;
	}
	void setMoveUp(ICommand* command)
	{
		moveUp = command;
	}
	void setMoveDown(ICommand* command)
	{
		moveDown = command;
	}
	void setMoveRightUp(ICommand* command)
	{
		moveRightUp = command;
	}
	void setMoveRightDown(ICommand* command)
	{
		moveRightDown = command;
	}
	void setMoveLeftUp(ICommand* command)
	{
		moveLeftUp = command;
	}
	void setMoveLeftDown(ICommand* command)
	{
		moveLeftDown = command;
	}
	ICommand* handleInput();
};

