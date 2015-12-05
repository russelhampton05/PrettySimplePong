#pragma once
#include "IUpdatable.h"
class Paddle : public IUpdatable, public sf::RectangleShape
{

private:
	sf::Vector2<double> maxVelocity;
	sf::Vector2<double> acceleration; 
	sf::Vector2<double> friction;
	//current vectory

	sf::Vector2f paddleSize;
public:
	Paddle()
	{
		paddleSize.x = Constants::PADDLE_WIDTH;
		paddleSize.y = Constants::PADDLE_LENGTH;
		setSize(paddleSize);
		setPosition((Constants::PADDLE_WIDTH / 2) + 10, (Constants::PADDLE_LENGTH / 2) + 2);
	}
	~Paddle();
	void update();
};

