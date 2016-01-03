#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "GameScreen.h"

int main()
{ 
	std::vector<IScreen*> screens;

	int screen = 0;

	sf::RenderWindow window(sf::VideoMode(Constants::windowXSize, Constants::windowYSize), "PSPong");

	GameScreen gameScreen;

	screens.push_back(&gameScreen);

	while (screen >= 0)
	{
		screen = screens[screen]->Run(window);
	}

	return 0;
}