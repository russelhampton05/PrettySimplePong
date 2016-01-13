#include "ArtificialPaddle.h"
#include <math.h>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "InputHandler.h"
#include "ICommand.h"
ArtificialPaddle::ArtificialPaddle(InputHandler& input)
{
	this->inputHandler = &input;
}


ArtificialPaddle::~ArtificialPaddle()
{
	closestBall = nullptr;
}

void ArtificialPaddle::onNotify(const Ball* ball)
{
	if (closestBall == nullptr)
	{
		closestBall = ball;
	}
	if (distanceToPaddle(closestBall->getPosition()) > distanceToPaddle(ball->getPosition()))
	{
//		std::cout << "Change ball \n";
		closestBall = ball;
	}
}
double ArtificialPaddle::distanceToPaddle(sf::Vector2f otherBall)
{
	double toBeRooted = (std::pow((otherBall.x - paddle->getPosition().x), 2) + std::pow((otherBall.y - paddle->getPosition().y), 2));
	if (toBeRooted < 0)
	{
		toBeRooted = toBeRooted * -1;
	}
	return std::sqrt(toBeRooted);
}

void ArtificialPaddle::makeMove()
{
	if (!closestBall)
	{
		return;
	}
	ICommand* command = nullptr;
	sf::Vector2f paddlePosition = paddle->getPosition();
	paddlePosition.y = paddlePosition.y + paddle->getPaddleSize().y / 2; //adjust to center of paddle
	sf::Vector2f ballPosition = closestBall->getPosition();

	if (paddlePosition.y - 5> ballPosition.y + Constants::BALLSIZE)
	{
		command = inputHandler->getMoveUp();
	}
	else if (paddlePosition.y + 5 < ballPosition.y - Constants::BALLSIZE)
	{
		command = inputHandler->getMoveDown();
	}
	else if (!command)
	{
		command = inputHandler->getNoCommand();
	}

	if (command)
	{
		command->execute(*paddle);
	}
}