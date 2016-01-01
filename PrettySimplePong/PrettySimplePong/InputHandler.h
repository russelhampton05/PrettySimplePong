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
	int id;
public:
	int getID()
	{
		return id;
	}
	void setID(int otherID)
	{
		id = otherID;
	}
	InputHandler();
	~InputHandler();
	ICommand* getMoveDown()
	{
		return moveDown;
	}
	ICommand* getMoveUp()
	{
		return moveUp;
	}
	ICommand* getMoveLeft()
	{
		return moveLeft;
	}
	ICommand* getNoCommand()
	{
		return noCommand;
	}
	ICommand* getMoveRight()
	{
		return moveRight;
	}
	ICommand* getMoveDownLeft()
	{
		return moveLeftDown;
	}
	ICommand* getMoveDownRight()
	{
		return moveRightDown;
	}
	ICommand* getMoveUpLeft()
	{
		return moveLeftUp;
	}
	ICommand* getMoveUpRight()
	{
		return moveRightUp;
	}
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

