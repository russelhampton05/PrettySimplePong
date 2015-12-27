#pragma once
class IMovable
{
public:
	IMovable();
	~IMovable();

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void moveRightUp() = 0;
	virtual void moveRightDown() = 0;
	virtual void moveLeftUp() = 0;
	virtual void moveLeftDown() = 0;
	virtual void noCommand() = 0;

};

