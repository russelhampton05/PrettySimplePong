#pragma once
#include "IUpdatable.h"
#include "IMovable.h"

class CollisionHandler;
class Paddle : public IUpdatable, public IMovable, public sf::RectangleShape
{
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
	sf::Vector2<double> acceleration; 
	sf::Vector2<double> friction;
	sf::Vector2f paddleSize;
	
	CollisionHandler* collisionHandler;
	PaddleBoundry boundry;
	PaddleMoving moving;
	int id;

	void setBoundry(Constants::WallSide paddleSide);
	void checkBoundry();
public:
	Paddle(Constants::WallSide paddleSide)
	{
		
		maxVelocity.x = Constants::PADDLE_VELOCITY_X;
		maxVelocity.y = Constants::PADDLE_VELOCITY_Y;
		

		setBoundry(paddleSide);
	}
	~Paddle();

	
	void setID(int id)
	{
		this->id = id;
	}
	int getID()
	{
		return id;
	}

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
	sf::Vector2f getPaddleSize()
	{
		return paddleSize;
	}
	PaddleBoundry getBoundry()
	{
		return boundry;
	}

	sf::Vector2<double> getVelocity();

	void setCollisionHandler(CollisionHandler& collisionHandler)
	{
		this->collisionHandler = &collisionHandler;
	}
};

