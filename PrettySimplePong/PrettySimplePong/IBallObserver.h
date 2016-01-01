#pragma once
#include "SFML\Graphics\CircleShape.hpp"
class Ball;
class IBallObserver
{
public:
	IBallObserver();
	~IBallObserver();
	void virtual onNotify(const Ball*) = 0;
};

