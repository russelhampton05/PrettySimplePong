#pragma once
class ICommand;
class InputHandler
{
private:
	ICommand* moveDown;
	ICommand* moveUp;
	ICommand* moveLeft;
	ICommand* moveRight;
public:
	InputHandler();
	~InputHandler();
	void setMoveRight(ICommand* command)
	{
		moveRight = command;
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
	ICommand* handleInput();
};

