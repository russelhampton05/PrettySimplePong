#pragma once
#include "IUpdatable.h"
#include "IMovable.h"

class Paddle : public IUpdatable, public IMovable, public sf::RectangleShape
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
		maxVelocity.x = 15;
		maxVelocity.y = 15;
		setPosition((Constants::PADDLE_WIDTH / 2) + 10, (Constants::PADDLE_LENGTH / 2) + 2);
	}
	~Paddle();
	void update();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

