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
public:
	GameScreen()
		:gameObjects(inputHandler)
	{
		inputHandler.setID(1);
		inputHandler.setMoveDown(&moveDownCommand);
		inputHandler.setMoveUp(&moveUpCommand);
		inputHandler.setMoveLeft(&moveLeftCommand);
		inputHandler.setMoveRight(&moveRightCommand);
		inputHandler.setMoveLeftUp(&moveLeftUpCommand);
		inputHandler.setMoveLeftDown(&moveLeftDownCommand);
		inputHandler.setMoveRightUp(&moveRightUpCommand);
		inputHandler.setMoveRightDown(&moveRightDownCommand);
		inputHandler.setNoCommand(&noCommand);





		gameObjects.addBall(30, 40);
		gameObjects.addBall(40, 300);
		gameObjects.addPlayerPaddle(Constants::LEFT, 1);
		gameObjects.addAiPaddle(Constants::RIGHT);
	}
	~GameScreen();
	int Run(sf::RenderWindow &window);
};

