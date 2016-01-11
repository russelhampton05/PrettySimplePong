#include "CollisionHandler.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
CollisionHandler::CollisionHandler()
{
}


CollisionHandler::~CollisionHandler()
{
}

//After a collision the ball will gain velocity based on paddle velocity.
sf::Vector2<double> CollisionHandler::checkCollision(Ball* ball) 
{
	//gather data
	float ballX = ball->getPosition().x; 
	float ballY = ball->getPosition().y;
	double ballVelocityX = ball->getVelocity().x;
	double ballVelocityY = ball->getVelocity().y;
	double ballRadius = ball->get_Radius();
	sf::Vector2<double> returnVelocity;
	returnVelocity.x = ballVelocityX;
	returnVelocity.y = ballVelocityY;

	for (auto paddle = paddles.begin(); paddle != paddles.end(); paddle++) 
	{
		double paddleWidth = (*paddle)->getPaddleSize().x;
		double paddleLength = (*paddle)->getPaddleSize().y;
		double paddleX = (*paddle)->getPosition().x;
		double paddleY = (*paddle)->getPosition().y;
		double paddleVelocityX = (*paddle)->getVelocity().x;
		double paddleVelocityY = (*paddle)->getVelocity().y;

		//Set ball position to on the paddle and then return the remaining velocity to the ball for handling by the ball
		switch ((*paddle)->getBoundry().side) 
		{
			case Constants::WallSide::LEFT :
			case Constants::WallSide::RIGHT:
				//determines what side of the paddle we're on
				if (ballVelocityX < 0 && ballX>paddleX)
				{
					if ((ballX + ballVelocityX - ballRadius) < (paddleX + paddleWidth) && (ballY - ballVelocityY - Constants::BALLSIZE) < (paddleY + paddleLength)
						&& (ballY - ballVelocityY + Constants::BALLSIZE) > paddleY)
					{
						//current ballVelocity - the distance to the paddle and then add the paddle's velocity 
						
						returnVelocity.x = (ballVelocityX*-1) - ((ballX - ballRadius) - (paddleX + paddleWidth)) + paddleVelocityX;
						returnVelocity.y = ballVelocityY*(((ballX - ballRadius) - (paddleX + paddleWidth)) / ballVelocityX);
						
						//set the ball to on the paddle and then return the left over velocity it took to get there
						double newBallX = ballRadius+(paddleX + paddleWidth);
						double newBallY = ballY + (ballVelocityY - returnVelocity.y);
						ball->setPosition(newBallX, newBallY);
						
						//new ball velocity
						sf::Vector2<double> newBallVelocity;

						newBallVelocity.x = (ballVelocityX *-1);
						if (paddleVelocityX > 0)
						{
							newBallVelocity.x += paddleVelocityX;
						}
						newBallVelocity.y = ballVelocityY + paddleVelocityY;
						ball->setVelocity(newBallVelocity);
					}
				}
				else if (ballVelocityX > 0 && ballX < paddleX)
				{
					if ((ballX + ballVelocityX + ballRadius) >(paddleX) && (ballY - ballVelocityY - Constants::BALLSIZE) < (paddleY + paddleLength)
						&& (ballY - ballVelocityY + Constants::BALLSIZE) > paddleY)
					{
						//current ballVelocity - the distance to the paddle and then add the paddle's velocity 

						returnVelocity.x = (ballVelocityX*-1) - ((ballX + ballRadius) - paddleX)+ paddleVelocityX;
						returnVelocity.y = ballVelocityY*(((ballX + ballRadius) - (paddleX)) / ballVelocityX);

						//set the ball to on the paddle and then return the left over velocity it took to get there
						double newBallX = (paddleX) - ballRadius;
						double newBallY = ballY + (ballVelocityY - returnVelocity.y);
						ball->setPosition(newBallX, newBallY);

						//new ball velocity
						sf::Vector2<double> newBallVelocity;
						newBallVelocity.x = (ballVelocityX*-1);
						if (paddleVelocityX < 0)
						{
							newBallVelocity.x += paddleVelocityX;
						}
						newBallVelocity.y = ballVelocityY + paddleVelocityY;
						ball->setVelocity(newBallVelocity);
						
					
					}
				}
				break;

				
		}
	}

	return returnVelocity;
}

//General behavior is that the paddle is immovable. The paddle's velocity will never be impacted by the ball collisions.
bool CollisionHandler::checkCollision(Paddle* paddle)
{
	bool collisionOccured = false;
	double paddleX = paddle->getPosition().x;
	double paddleY = paddle->getPosition().y;
	sf::Vector2<double> paddleVelocity = paddle->getVelocity();
	for (auto ball = balls.begin(); ball != balls.end(); ball++)
	{
	
		double ballX = (*ball)->getPosition().x;
		double ballY = (*ball)->getPosition().y;
		sf::Vector2<double> ballVelocity = (*ball)->getVelocity();

		switch (paddle->getBoundry().side)
		{
		case Constants::WallSide::LEFT:
		case Constants::WallSide::RIGHT:
			if (paddleVelocity.x > 0 && paddleX < ballX)
			{
				if ((paddleX + Constants::PADDLE_WIDTH + paddleVelocity.x > ballX - Constants::BALLSIZE) &&
					ballY - Constants::BALLSIZE < (paddleY + Constants::PADDLE_LENGTH + paddleVelocity.y) &&
					ballY + Constants::BALLSIZE > paddleY + paddleVelocity.y)
				{
					collisionOccured = true;

					//Set the ball's position to where the paddle will end up at the end of its frame.

					(*ball)->setPosition(paddleX + Constants::PADDLE_WIDTH + paddleVelocity.x + Constants::BALLSIZE, ballY);
					if (ballVelocity.x > 0)
					{
						ballVelocity.x = (ballVelocity.x) + paddleVelocity.x;
					}
					else
					{
						ballVelocity.x = (-1 * ballVelocity.x) + paddleVelocity.x;
					}
					ballVelocity.y = ballVelocity.y + paddleVelocity.y;
					(*ball)->setVelocity(ballVelocity);
				}
			}
			else if (paddleVelocity.x < 0 && paddleX > ballX)
			{
				if (paddleX + paddleVelocity.x < (ballX + Constants::BALLSIZE) &&
					ballY - Constants::BALLSIZE < (paddleY + Constants::PADDLE_LENGTH + paddleVelocity.y) &&
					ballY + Constants::BALLSIZE > paddleY + paddleVelocity.y)
				{
					collisionOccured = true;

					//Set the ball's position to where the paddle will end up at the end of its frame.

					(*ball)->setPosition(paddleX + paddleVelocity.x - Constants::BALLSIZE, ballY) ;
					if (ballVelocity.x < 0)
					{
						ballVelocity.x = (ballVelocity.x) + paddleVelocity.x;
					}
					else
					{
						ballVelocity.x = (-1 * ballVelocity.x) + paddleVelocity.x;
					}
					ballVelocity.y = ballVelocity.y + paddleVelocity.y;
					(*ball)->setVelocity(ballVelocity);
					
				}
			}
		}
		break;

	}

	return collisionOccured;
} 