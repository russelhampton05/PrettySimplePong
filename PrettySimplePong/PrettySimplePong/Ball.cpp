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
	if (((x - Constants::BALLSIZE) + velocity.x)< -10)
	{
		collisionOccured = true;
		Notify(Constants::WallHit::LEFT);
		if (velocity.x < 0)
		{
			velocity.x = velocity.x*-1;
		}
		peekX = ((velocity.x) - (x - Constants::BALLSIZE)) + Constants::BALLSIZE -10; //-10 because SFML seems to draw the window and the drawing space a bit off
		peekY = y;
	}
	else if ((x + velocity.x + Constants::BALLSIZE) > Constants::windowXSize)
	{
		collisionOccured = true;
		Notify(Constants::WallHit::RIGHT);
		if (velocity.x > 0)
		{
			velocity.x = velocity.x*-1;
		}

		peekX = Constants::windowXSize + ((velocity.x) + (Constants::windowXSize - (x + Constants::BALLSIZE))) - Constants::BALLSIZE;
		peekY = y;
	
	
	}
	
	else if (y + velocity.y - Constants::BALLSIZE<- 10 )
	{
		collisionOccured = true;
		Notify(Constants::WallHit::UP);
		if (velocity.y < 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = (velocity.y) - (y - Constants::BALLSIZE) + Constants::BALLSIZE - 10;
	
		
	}
	else if (y + velocity.y + Constants::BALLSIZE > Constants::windowYSize)
	{
		collisionOccured = true;
		Notify(Constants::WallHit::DOWN);
		if (velocity.y > 0)
		{
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = Constants::windowYSize + ((velocity.y) + (Constants::windowYSize - (y + Constants::BALLSIZE))) - Constants::BALLSIZE;
	
	}

	if (collisionOccured)
	{
		setPosition(peekX, peekY);
	}

	return collisionOccured;
}

void Ball::Notify(Constants::WallHit hit)
{
	for (auto iterator = wallObservers.begin(); iterator != wallObservers.end(); iterator++)
	{
		(*iterator)->onNotify(hit);
	}
}

