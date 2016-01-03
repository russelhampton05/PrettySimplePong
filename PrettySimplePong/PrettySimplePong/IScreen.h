#pragma once
#include "SFML\Graphics.hpp"
class IScreen
{
public:
	IScreen();
	virtual ~IScreen();
	virtual int Run(sf::RenderWindow &window) = 0;
};

