#pragma once
#include "IScreen.h"
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include "GameObjects.h"
#include "MoveDownCommand.h"
#include "MoveUpCommand.h"
#include "MoveRDCommand.h"
#include "MoveLDCommand.h"
#include "MoveLUCommand.h"
#include "MoveRUCommand.h"
#include "MoveLeftCommand.h"
#include "NoCommand.h"
#include "MoveRightCommand.h"
#include "InputHandler.h"
#include "menuChoices.h"
class GameScreen :
	public IScreen
{ 
	
private:
	MoveUpCommand moveUpCommand;
	MoveDownCommand moveDownCommand;
	MoveLeftCommand moveLeftCommand;
	MoveRightCommand moveRightCommand;
	MoveRDCommand moveRightDownCommand;
	MoveLDCommand moveLeftDownCommand;
	MoveRUCommand moveRightUpCommand;
	MoveLUCommand moveLeftUpCommand;
	NoCommand noCommand;
	CollisionHandler collisionHandler;
	GameObjects gameObjects;
	InputHandler inputHandler;
	sf::Font pauseFont;
	sf::Text pauseText;
	sf::Color BGcolor;

	menuChoices* choices;

	void addBalls();
	void setBGColor();
	void addPaddles();
public:
	GameScreen(menuChoices& choices)
		:gameObjects(inputHandler, choices)
	{
		this->choices = &choices;

		inputHandler.setID(0);
		inputHandler.setMoveDown(&moveDownCommand);
		inputHandler.setMoveUp(&moveUpCommand);
		inputHandler.setMoveLeft(&moveLeftCommand);
		inputHandler.setMoveRight(&moveRightCommand);
		inputHandler.setMoveLeftUp(&moveLeftUpCommand);
		inputHandler.setMoveLeftDown(&moveLeftDownCommand);
		inputHandler.setMoveRightUp(&moveRightUpCommand);
		inputHandler.setMoveRightDown(&moveRightDownCommand);
		inputHandler.setNoCommand(&noCommand);

		if (!pauseFont.loadFromFile("timesbd.ttf"))
		{
			if (!pauseFont.loadFromFile("C:\Windows\Fonts\Times New Roman\timesbd.ttf"))
			{
				std::cout << "Failed to load font times new roman from  file timesbd.ttf \n Please put the in the same folder as the .exe or in C:\Windows\Fonts";
			}
		}

		setBGColor();
		addBalls();
		addPaddles();
	}
	~GameScreen();
	int Run(sf::RenderWindow &window);
};

