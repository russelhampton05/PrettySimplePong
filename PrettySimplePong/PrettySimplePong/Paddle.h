#pragma once
#include "IUpdatable.h"
#include "IMovable.h"
class menuChoices;
class CollisionHandler;

class Paddle : public IUpdatable, public IMovable, public sf::RectangleShape
{
	//The paddle's velocity is constant. These flags represent which direction the paddle is currently moving.
	struct PaddleMoving
	{
		bool moveUp = false;
		bool moveDown = false;
		bool moveLeft = false;
		bool moveRight = false;
		bool moveUpLeft = false;
		bool moveUpRight = false;
		bool moveDownLeft = false;
		bool moveDownRight = false;
		
		void setFalse()
		{
			moveUp = false;
			moveDown = false;
			moveLeft = false;
			moveRight = false;
			moveUpLeft = false;
			moveUpRight = false;
			moveDownLeft = false;
			moveDownRight = false;
		}
	};
	struct PaddleBoundry 
	{
		Constants::WallSide side;
		float minX;
		float maxX;
		float minY;
		float maxY;
	};
private:

	sf::Vector2<double> maxVelocity;
	sf::Vector2f paddleSize;
	Constants::WallSide paddleSide;

	CollisionHandler* collisionHandler;
	menuChoices* choices;
	PaddleBoundry boundry;
	PaddleMoving moving;
	int id;

	void setBoundry();
	void checkBoundry();
public:
	Paddle(Constants::WallSide paddleSide, menuChoices& choices)
	{
		this->choices = &choices;
		maxVelocity.x = Constants::PADDLE_VELOCITY_X;
		maxVelocity.y = Constants::PADDLE_VELOCITY_Y;
		this->paddleSide = paddleSide;

		setBoundry();
	}
	~Paddle();



	void update();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void moveRightDown();
	void moveLeftDown();
	void moveRightUp();
	void moveLeftUp();
	void noCommand();
	sf::Vector2<double> getVelocity();


	sf::Vector2f getPaddleSize()
	{
		return paddleSize;
	}
	PaddleBoundry getBoundry()
	{
		return boundry;
	}
	void setCollisionHandler(CollisionHandler& collisionHandler)
	{
		this->collisionHandler = &collisionHandler;
	}
	void setLength(double length)
	{
		paddleSize.y = length;
		setBoundry();
	}
	void setID(int id)
	{
		this->id = id;
	}
	int getID()
	{
		return id;
	}
};

