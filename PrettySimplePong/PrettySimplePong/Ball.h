#pragma once

#include "IUpdatable.h"
#include <vector>
#include "IWallObserver.h"
class Ball: public IUpdatable, public sf::CircleShape
{
private:
	sf::Vector2<double> velocity;
	std::vector<IWallObserver*> wallObservers;
	void Notify(Constants::WallHit);
	//Peek values are place holders so that a previous update cycle's wall collision
	//result can be passed ahead to the next draw phase.
	
public:
	Ball()
	{
		CircleShape::setPosition(Constants::START_X, Constants::START_Y);
		CircleShape::setRadius(Constants::BALLSIZE);
		velocity.x = 10;
		velocity.y = 4;
		
	}
	void update();
	void addWallObserver(IWallObserver& observer)
	{
		observer.id = wallObservers.size();
		wallObservers.push_back(&observer);
	}
	void removeWallObserver(IWallObserver& observer)
	{
		for (auto iterator = wallObservers.begin(); iterator != wallObservers.end(); iterator++)
		{
			(*iterator)->id == observer.id;
			wallObservers.erase(iterator);
			break;
		}
	}
	bool handleWallCollision();
	
	~Ball();
};


