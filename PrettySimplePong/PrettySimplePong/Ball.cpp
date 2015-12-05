#include "Ball.h"


Ball::~Ball()
{
}


void Ball::update()
{
	setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
	handleWallCollision();
}

void Ball::handleWallCollision()
{
	int x = getPosition().x;
	int y = getPosition().y;
	//all four of these events will have to go into an observer pattern so a score ticker can be prompted
	if (x - Constants::BALLSIZE +8< 0)
	{
		if (velocity.x < 0)
		{
			velocity.x = velocity.x*-1;
		}
	}
	else if (x + Constants::BALLSIZE + 8 > Constants::windowXSize)
	{
		if (velocity.x > 0)
		{
			velocity.x = velocity.x*-1;
		}
	}
	
	if (y - Constants::BALLSIZE +8 < 0)
	{
		if (velocity.y < 0)
		{
			velocity.y = velocity.y * -1;
		}
	}
	else if (y + Constants::BALLSIZE + 8 > Constants::windowYSize)
	{
		if (velocity.y > 0)
		{
			velocity.y = velocity.y * -1;
		}
	}
}

