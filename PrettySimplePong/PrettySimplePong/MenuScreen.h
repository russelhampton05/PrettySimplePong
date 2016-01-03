#pragma once
#include "IScreen.h"
class MenuScreen :
	public IScreen
{
public:
	MenuScreen();
	~MenuScreen();

	int Run(sf::RenderWindow &window);
};

