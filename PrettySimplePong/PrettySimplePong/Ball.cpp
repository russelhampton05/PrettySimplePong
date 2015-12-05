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

	if (x - Constants::BALLSIZE < 0 || x + Constants::BALLSIZE > Constants::windowXSize)
	{
		velocity.x = velocity.x*-1;
	}
	
	if (y - Constants::BALLSIZE < 0 || y + Constants::BALLSIZE > Constants::windowYSize)
	{
		velocity.y = velocity.y * -1;
	}
}

