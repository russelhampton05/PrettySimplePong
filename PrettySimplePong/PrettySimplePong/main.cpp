#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "GameScreen.h"
#include "MenuScreen.h"
#include <iostream>

void messageFromSponsors();
int main()
{ 
	//For more information see the read me. You can also check out the repository on github. https://github.com/russelhampton05/PrettySimplePong
	messageFromSponsors();
	IScreen** screens = new IScreen*[2];

	int screen = 1;

	sf::RenderWindow window(sf::VideoMode(Constants::windowXSize, Constants::windowYSize), "PSPong");

	MenuScreen menuScreen;
	GameScreen* gameScreen = new GameScreen(menuScreen.getChoices());
	screens[(int)Constants::GAME_SCREEN] = gameScreen;
	screens[(int)Constants::MENU_SCREEN] = (&menuScreen);
	while (screen >= 0)
	{
		screen = screens[screen]->Run(window);
		if (screen == Constants::RESET_GAMESCREEN)
		{
			delete gameScreen;
			gameScreen = new GameScreen(menuScreen.getChoices());
			screens[(int)Constants::GAME_SCREEN] = gameScreen;
			screen = Constants::GAME_SCREEN;
		}
	}

	delete screens[(int)Constants::GAME_SCREEN];

	return 0;
}

void messageFromSponsors()
{
	std::cout << "For more information see the read me file included or visit \n https://github.com/russelhampton05/PrettySimplePong \n";
}