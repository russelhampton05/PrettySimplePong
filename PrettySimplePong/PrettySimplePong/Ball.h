#pragma once

#include "IUpdatable.h"

class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;

	//Peek values are place holders so that a previous update cycle's wall collision
	//result can be passed ahead to the next draw phase.
	double peekX;	
	double peekY;
public:
	Ball()
	{
		CircleShape::setPosition(Constants::START_X, Constants::START_Y);
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = -8;
		velocity.y = 25;
		peekX = Constants::EMPTY;
		peekY = Constants::EMPTY;
	}
	void update();
	bool wallCollisionCheck();
	void handleWallCollision();
	~Ball();
};


