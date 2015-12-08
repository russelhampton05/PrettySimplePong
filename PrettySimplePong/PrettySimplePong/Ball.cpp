#include "Ball.h"


Ball::~Ball()
{
}


void Ball::update()
{
	if (peekX == Constants::EMPTY && peekY == Constants::EMPTY)
	{
		setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
	}
	else
	{
		setPosition(peekX, peekY);
		peekX = Constants::EMPTY;
		peekY = Constants::EMPTY;
	}
		handleWallCollision();
	
}

void Ball::handleWallCollision()
{
	int x = getPosition().x;
	int y = getPosition().y;
	//all four of these events will have to go into an observer pattern so a score ticker can be prompted

	//check to see if next velocity tick will place ball out of bounds and instead update as if the bounce happened
	//between updates
	if ((x + velocity.x - Constants::BALLSIZE) < 0)
	{
		if (velocity.x < 0)
		{
			velocity.x = velocity.x*-1;
		}
		
		peekX = (velocity.x) - (x - Constants::BALLSIZE);
		peekY = y;
	}
	else if ((x + velocity.x + Constants::BALLSIZE) > Constants::windowXSize)
	{
		if (velocity.x > 0)
		{
			velocity.x = velocity.x*-1;
		}

		peekX = Constants::windowXSize - ((velocity.x) - (Constants::windowXSize - (x + Constants::BALLSIZE)));
		peekY = y;
	}
	
	if (y + velocity.y - Constants::BALLSIZE < 0)
	{
		if (velocity.y < 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = (velocity.y) - (y - Constants::BALLSIZE);
	}
	else if (y + velocity.y + Constants::BALLSIZE > Constants::windowYSize)
	{
		if (velocity.y > 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = Constants::windowYSize - ((velocity.y) - (Constants::windowYSize - (y + Constants::BALLSIZE)));
	}
}

