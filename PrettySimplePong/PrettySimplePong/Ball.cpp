#include "Ball.h"
#include <iostream>

Ball::~Ball()
{
}


void Ball::update()
{
	bool collisionOccured = false;
		collisionOccured = handleWallCollision();	
		if (!collisionOccured)
		{
			setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
			std::cout << getPosition().x << " " << getPosition().y << "\n";
		}
		
}

bool Ball::handleWallCollision()
{
	bool collisionOccured = false;
	float peekX;
	float peekY;
	float x = getPosition().x;
	float y = getPosition().y;
	//all four of these events will have to go into an observer pattern so a score ticker can be prompted

	//check to see if next velocity tick will place ball out of bounds and instead update as if the bounce happened
	//between updates
	if (((x - Constants::BALLSIZE) + velocity.x)< -8)
	{
		collisionOccured = true;
		if (velocity.x < 0)
		{
			velocity.x = velocity.x*-1;
		}
		
		peekX = (velocity.x) - (x - Constants::BALLSIZE)-8;
		peekY = y;
	}
	else if ((x + velocity.x + Constants::BALLSIZE) > Constants::windowXSize)
	{
		collisionOccured = true;
		if (velocity.x > 0)
		{
			velocity.x = velocity.x*-1;
		}

		peekX = Constants::windowXSize - ((velocity.x) - (Constants::windowXSize - (x + Constants::BALLSIZE)));
		peekY = y;
	}
	
	else if (y + velocity.y - Constants::BALLSIZE< 0)
	{
		collisionOccured = true;
		if (velocity.y < 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = (velocity.y) - (y - Constants::BALLSIZE);
		std::cout << "PEEK Y" << peekY << "\n";
	}
	else if (y + velocity.y + Constants::BALLSIZE > Constants::windowYSize)
	{
		collisionOccured = true;
		if (velocity.y > 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = Constants::windowYSize - ((velocity.y) - (Constants::windowYSize - (y + Constants::BALLSIZE)));
	}

	if (collisionOccured)
	{
		setPosition(peekX, peekY);
	}

	return collisionOccured;
}

