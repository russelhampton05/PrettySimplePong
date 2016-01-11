#include "Paddle.h"

#include "CollisionHandler.h"
#include "menuChoices.h"

Paddle::~Paddle()
{
}


void Paddle::update()
{
	double xVelocity = getVelocity().x;
	double yVelocity = getVelocity().y;
	collisionHandler->checkCollision(this);

	setPosition(getPosition().x + xVelocity, getPosition().y + yVelocity);
	checkBoundry();
	//moving.setFalse();
}

//These functions control the moving flags to deteremine direction of paddle based on last input
void Paddle::moveUp()
{
	
	moving.setFalse();
	moving.moveUp = true;
}
void Paddle::moveDown()
{
	moving.setFalse();
	moving.moveDown = true;
}
void Paddle::moveLeft()
{
	moving.setFalse();
	moving.moveLeft = true;
}
void Paddle::moveRight()
{
	checkBoundry();
	moving.setFalse();
	moving.moveRight = true;
}

void Paddle::moveRightDown()
{
	moving.setFalse();
	moving.moveDownRight = true;
}

void Paddle::moveRightUp()
{
	moving.setFalse();
	moving.moveUpRight = true;
}
void Paddle::moveLeftDown()
{
	moving.setFalse();
	moving.moveDownLeft = true;
}
void Paddle::moveLeftUp()
{
	checkBoundry(); moving.setFalse();

	moving.moveUpLeft = true;
}
void Paddle::noCommand()
{
	 moving.setFalse();
}
//Paddles can go on any side, so the math will be different accordingly.
void Paddle::setBoundry()
{
	switch (paddleSide)
	{
	case::Constants::WallSide::LEFT:

		setPosition((Constants::PADDLE_WIDTH / 2) + 5, Constants::windowYSize / 2);
		paddleSize.x = Constants::PADDLE_WIDTH;
		paddleSize.y = paddleSize.y;
		setSize(paddleSize);

		boundry.maxX = (Constants::windowXSize / 2 - 10) - (Constants::PADDLE_WIDTH);
		boundry.maxY = (Constants::windowYSize) - (choices->paddleSize);
		boundry.minX = 0;
		boundry.minY = 0;
		boundry.side = paddleSide;
		break;
	case::Constants::WallSide::RIGHT:

		setPosition(Constants::windowXSize - (Constants::PADDLE_WIDTH / 2) - 5, Constants::windowYSize / 2);
		paddleSize.x = Constants::PADDLE_WIDTH;
		paddleSize.y = paddleSize.y;
		setSize(paddleSize);

		boundry.maxX = Constants::windowXSize - Constants::PADDLE_WIDTH;
		boundry.maxY = (Constants::windowYSize) - (choices->paddleSize);
		boundry.minX = (Constants::windowXSize / 2 + 10) + (Constants::PADDLE_WIDTH);
		boundry.minY = 0;
		boundry.side = paddleSide;
	}
}
//this makes sure we dont have paddles running off screen.
void Paddle::checkBoundry()
{
	float currentX = getPosition().x;
	float currentY = getPosition().y;

	if (currentX > boundry.maxX)
	{
		currentX = boundry.maxX;
	}
	else if (currentX < boundry.minX)
	{
		currentX = boundry.minX;
	}
	if (currentY > boundry.maxY)
	{
		currentY = boundry.maxY;
	}
	else if (currentY < boundry.minY)
	{
		currentY = boundry.minY;
	}

	setPosition(currentX, currentY);

}

//Getting the paddle velocity involves knowing which command was previously given.
sf::Vector2<double> Paddle::getVelocity()
{

	sf::Vector2<double> returnVector;
	returnVector.x = 0;
	returnVector.y = 0;
	if (moving.moveDown)
	{
		returnVector.y = maxVelocity.y;
		returnVector.x = 0;
	}
	else if (moving.moveUp)
	{
		returnVector.y = -maxVelocity.y;
		returnVector.x = 0;
	}
	else if (moving.moveLeft)
	{
		returnVector.y = 0;
		returnVector.x = -maxVelocity.x;
	}
	if (moving.moveRight)
	{
		returnVector.y = 0;
		returnVector.x = maxVelocity.x;
	}
	else if (moving.moveDownLeft)
	{
		returnVector.y = maxVelocity.y;
		returnVector.x = -maxVelocity.x;
	}
	else if (moving.moveDownRight)
	{
		returnVector.y = maxVelocity.y;
		returnVector.x = maxVelocity.x;
	}
	if (moving.moveUpLeft)
	{
		returnVector.y = -maxVelocity.y;
		returnVector.x = -maxVelocity.x;
	}
	else if (moving.moveUpRight)
	{
		returnVector.y = -maxVelocity.y;
		returnVector.x = maxVelocity.x;
	}

	return returnVector;
}

