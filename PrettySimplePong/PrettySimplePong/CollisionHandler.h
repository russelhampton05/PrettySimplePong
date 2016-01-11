#pragma once
#include "Constants.h"
#include <vector>
#include "SFML\Graphics.hpp"
class Ball;
class Paddle;
//
class CollisionHandler
{ 

private:
	std::vector<Paddle*> paddles;
	std::vector<Ball*> balls;
public:
	CollisionHandler();
	~CollisionHandler(); 

	//sf::Vector2<double> checkCollision(Paddle&);
	sf::Vector2<double> checkCollision(Ball*);
	bool checkCollision(Paddle*);
	void registerPaddle(Paddle& paddle)
	{
		paddles.push_back(&paddle);
	}
	void registerBall(Ball& ball)
	{
		balls.push_back(&ball);
	}

};

