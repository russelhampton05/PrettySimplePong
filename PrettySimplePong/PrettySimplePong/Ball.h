#pragma once

#include "IUpdatable.h"

class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;
public:
	Ball()
	{
		CircleShape::setPosition(Constants::START_X, Constants::START_Y);
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = 8;
		velocity.y = 5;

	}
	void update();
	bool wallCollisionCheck();
	void handleWallCollision();
	~Ball();
};


