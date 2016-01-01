#include "Ball.h"
//#include <iostream>
#include "CollisionHandler.h"
Ball::~Ball()
{
}


void Ball::update()
{
	sf::Vector2<double> calculatedVelocity;
	bool wallCollisionOccured = false;
	calculatedVelocity = collisionHandler->checkCollision(this); 
	wallCollisionOccured = handleWallCollision(calculatedVelocity);
	if (!wallCollisionOccured)
	{
		setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
		//std::cout << getPosition().x << " " << getPosition().y << "\n";
	}
	ApplyFriction();
	CheckVelocities();
	NotifyBallMove();
	//std::cout << velocity.x << " " << velocity.y << " \n";

}

bool Ball::handleWallCollision(sf::Vector2<double> calculatedVelocity)
{
	bool collisionOccured = false;
	float peekX;
	float peekY;
	float x = getPosition().x;
	float y = getPosition().y;
	//all four of these events will have to go into an observer pattern so a score ticker can be prompted

	//check to see if next calculatedVelocity tick will place ball out of bounds and instead update as if the bounce happened
	//between updates
	if (((x - Constants::BALLSIZE) + calculatedVelocity.x) < 0)
	{
		collisionOccured = true;
		NotifyWallHit(Constants::WallSide::LEFT);
		if (calculatedVelocity.x < 0)
		{
			calculatedVelocity.x = calculatedVelocity.x*-1;
			velocity.x = velocity.x * -1;
		}
		peekX = ((calculatedVelocity.x) - (x - Constants::BALLSIZE)) + Constants::BALLSIZE;
		peekY = y;
	}
	else if ((x + calculatedVelocity.x + Constants::BALLSIZE) > Constants::windowXSize)
	{
		collisionOccured = true;
		NotifyWallHit(Constants::WallSide::RIGHT);
		if (calculatedVelocity.x > 0)
		{
			calculatedVelocity.x = calculatedVelocity.x*-1;
			velocity.x = velocity.x * -1;
		}

		peekX = Constants::windowXSize + ((calculatedVelocity.x) + (Constants::windowXSize - (x + Constants::BALLSIZE))) - Constants::BALLSIZE;
		peekY = y;


	}

	else if (y + calculatedVelocity.y - Constants::BALLSIZE < 0)
	{
		collisionOccured = true;
		NotifyWallHit(Constants::WallSide::UP);
		if (calculatedVelocity.y < 0)
		{
			calculatedVelocity.y = calculatedVelocity.y * -1;
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = (calculatedVelocity.y) - (y - Constants::BALLSIZE) + Constants::BALLSIZE;


	}
	else if (y + calculatedVelocity.y + Constants::BALLSIZE > Constants::windowYSize)
	{
		collisionOccured = true;
		NotifyWallHit(Constants::WallSide::DOWN);
		if (calculatedVelocity.y > 0)
		{
			calculatedVelocity.y = calculatedVelocity.y * -1;
			velocity.y = velocity.y * -1;
		}
		peekX = x;
		peekY = Constants::windowYSize + ((calculatedVelocity.y) + (Constants::windowYSize - (y + Constants::BALLSIZE))) - Constants::BALLSIZE;

	}

	if (collisionOccured)
	{
		setPosition(peekX, peekY);
	}

	return collisionOccured;
}
void Ball::NotifyBallMove()
{
	for (auto iterator = ballObservers.begin(); iterator != ballObservers.end(); iterator++)
	{
		(*iterator)->onNotify(this);
	}
}
void Ball::NotifyWallHit(Constants::WallSide hit)
{
	for (auto iterator = wallObservers.begin(); iterator != wallObservers.end(); iterator++)
	{
		(*iterator)->onNotify(hit);
	}
}
void Ball::CheckVelocities()
{
	if (velocity.x > 0)
	{
		if (velocity.x < Constants::BALL_MIN_VELOCITY)
		{
			velocity.x = Constants::BALL_MIN_VELOCITY;
		}
		else if (velocity.x > Constants::BALL_MAX_VELOCITY)
		{
			velocity.x = Constants::BALL_MAX_VELOCITY;
		}
	}
	else if (velocity.x < 0)
	{

		if ((velocity.x*-1) < Constants::BALL_MIN_VELOCITY)
		{
			velocity.x = Constants::BALL_MIN_VELOCITY*-1;
		}
		else if ((velocity.x)*-1 > Constants::BALL_MAX_VELOCITY)
		{
			velocity.x = Constants::BALL_MAX_VELOCITY*-1;
		}

	}
	if (velocity.y > 0)
	{
		if (velocity.y < Constants::BALL_MIN_VELOCITY)
		{
			velocity.y = Constants::BALL_MIN_VELOCITY;
		}
		else if (velocity.y > Constants::BALL_MAX_VELOCITY)
		{
			velocity.y = Constants::BALL_MAX_VELOCITY;
		}
	}
	else if (velocity.y < 0)
	{
		if (velocity.y *-1< Constants::BALL_MIN_VELOCITY)
		{
			velocity.y = Constants::BALL_MIN_VELOCITY*-1;
		}
		else if (velocity.y*-1 > Constants::BALL_MAX_VELOCITY)
		{
			velocity.y = Constants::BALL_MAX_VELOCITY*-1;
		}
	}
}
void Ball::ApplyFriction()
{
	if (velocity.x > 0 && velocity.x - Constants::FRICTION > 0)
	{
		velocity.x = velocity.x - Constants::FRICTION;
	}
	else if (velocity.x < 0 && velocity.x - Constants::FRICTION < 0)
	{
		velocity.x = velocity.x + Constants::FRICTION;
	}
	if (velocity.y > 0 && velocity.y - Constants::FRICTION > 0)
	{
		velocity.y = velocity.y - Constants::FRICTION;
	}
	else if (velocity.y < 0 && velocity.y - Constants::FRICTION < 0)
	{
		velocity.y = velocity.y + Constants::FRICTION;
	}
	
}
	

