#include "Ball.h"


Ball::~Ball()
{
}


void Ball::update()
{
	setPosition(getPosition().x + velocity.x, getPosition().y + velocity.y);
}

