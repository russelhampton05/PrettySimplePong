#pragma once

#include "IUpdatable.h"

class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;
public:
	Ball()
	{
		CircleShape::setPosition(Constants::start_x, Constants::start_y);
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = 5;
		velocity.y = 1;
	}
	void update();
	
	~Ball();
};

