#include "Paddle.h"




Paddle::~Paddle()
{
}


void Paddle::update()
{

}

void Paddle::moveUp()
{
	int x = getPosition().x;
	int y = getPosition().y;

	setPosition(x, y - maxVelocity.y);
}
void Paddle::moveDown()
{
	int x = getPosition().x;
	int y = getPosition().y;

	setPosition(x, y + maxVelocity.y);
}
void Paddle::moveLeft()
{
	int x = getPosition().x;
	int y = getPosition().y;

	setPosition(x - maxVelocity.x, y);
}
void Paddle::moveRight()
{
	int x = getPosition().x;
	int y = getPosition().y;

	setPosition(x + maxVelocity.x, y);

}