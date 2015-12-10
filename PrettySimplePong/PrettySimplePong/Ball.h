#pragma once

#include "IUpdatable.h"

class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;
	

	//Peek values are place holders so that a previous update cycle's wall collision
	//result can be passed ahead to the next draw phase.
	
public:
	Ball()
	{
		CircleShape::setPosition(Constants::START_X, Constants::START_Y);
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = 10;
		velocity.y = 10;
		
	}
	void update();
	
	bool handleWallCollision();
	~Ball();
};


