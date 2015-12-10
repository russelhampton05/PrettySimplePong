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


};

