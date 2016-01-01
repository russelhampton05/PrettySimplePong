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

int main()
{ 

	sf::RenderWindow window(sf::VideoMode(Constants::windowXSize, Constants::windowYSize), "PSPong");

	time_t startTime;
	time_t endTime;

	

	//find a good way to clean this up next. This will most likely go to some sort of Menu class when the
	//menu UI is made. There will be a menu, definitely. Maybe.
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
	
	InputHandler inputHandler;
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

	GameObjects gameObjects(inputHandler);
	gameObjects.addBall(30, 40);
	gameObjects.addBall(40, 300);
	gameObjects.addPlayerPaddle(Constants::LEFT, 1);
	gameObjects.addAiPaddle(Constants::RIGHT);




	//GUI loop
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		time(&startTime);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		 window.clear(sf::Color::Blue);

		
		ICommand* command = nullptr;
		command = inputHandler.handleInput();
		if (command != nullptr)
		{
			gameObjects.giveCommand(inputHandler.getID(), *command);
		}
		gameObjects.aiMakeMove();

		//Drawing
		std::vector<sf::Drawable*> drawnObjects = gameObjects.getDrawables();
		for (auto drawnObject = drawnObjects.begin(); drawnObject != drawnObjects.end(); drawnObject++)
		{
			window.draw(**drawnObject);
		}
		
		gameObjects.update();
	

		// end the current frame
		window.display();
		time(&endTime);
		std::this_thread::sleep_for(std::chrono::milliseconds(startTime + Constants::FRAMERATE - endTime)); 
	   
		
	}
	gameObjects.deleteObjects();
	return 0;
}