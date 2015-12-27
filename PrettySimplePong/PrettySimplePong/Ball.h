#pragma once

#include "IUpdatable.h"
#include <vector>
#include "IWallObserver.h"
#include "IBallObserver.h"
class CollisionHandler;

class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;
	std::vector<IWallObserver*> wallObservers;
	std::vector<IBallObserver*> ballObservers;
	CollisionHandler* collisionHandler;

	void NotifyWallHit(Constants::WallSide);
	void NotifyBallMove();
	bool handleWallCollision(sf::Vector2<double>);
	void ApplyFriction();
	void CheckVelocities();
public:

	Ball()
	{
		CircleShape::setOrigin(Constants::BALLSIZE, Constants::BALLSIZE);
		CircleShape::setPosition(Constants::START_X, Constants::START_Y);
		
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = Constants::BALL_VELOCITY_X;
		velocity.y = Constants::BALL_VELOCITY_Y;
		
	}
	void update();

	void setCollisionHandler(CollisionHandler& handler)
	{
		collisionHandler = &handler;
	}
	sf::Vector2<double> getVelocity()
	{
		return velocity;
	}
	void setVelocity(sf::Vector2<double> newVelocity)
	{
		velocity = newVelocity;
	}
	double get_Radius()
	{
		return getRadius();
	}

	void addWallObserver(IWallObserver& observer)
	{
		wallObservers.push_back(&observer);
	}
	void removeWallObserver(IWallObserver& observer)
	{
		for (auto iterator = wallObservers.begin(); iterator != wallObservers.end(); iterator++)
		{
			if ((*iterator) == &observer)
			{
				wallObservers.erase(iterator);
			}
			break;
		}
		
	}
	
	
	~Ball();
};


