#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include "IUpdatable.h"
#include "Ball.h"
#include "Paddle.h"
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
#include"CollisionHandler.h"
#include "ScoreBoard.h"
int main()
{ 
	//Have not yet decided whether to move initialization to somewhere not here
	sf::RenderWindow window(sf::VideoMode(Constants::windowXSize, Constants::windowYSize), "PSPong");

	time_t startTime;
	time_t endTime;

	std::vector<sf::Drawable*> drawnObjects;
	std::vector<IUpdatable*> updateObjects;


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
	inputHandler.setMoveDown(&moveDownCommand);
	inputHandler.setMoveUp(&moveUpCommand);
	inputHandler.setMoveLeft(&moveLeftCommand);
	inputHandler.setMoveRight(&moveRightCommand);
	inputHandler.setMoveLeftUp(&moveLeftUpCommand);
	inputHandler.setMoveLeftDown(&moveLeftDownCommand);
	inputHandler.setMoveRightUp(&moveRightUpCommand);
	inputHandler.setMoveRightDown(&moveRightDownCommand);
	inputHandler.setNoCommand(&noCommand);

	Ball newBall;
	newBall.setCollisionHandler(collisionHandler);
	Paddle paddle1(Constants::WallSide::RIGHT);
	paddle1.setCollisionHandler(collisionHandler);
//	Paddle paddle2(Constants::WallSide::LEFT);
	ScoreBoard scoreBoard;
	newBall.addWallObserver(scoreBoard);
	drawnObjects.push_back(&newBall);
	drawnObjects.push_back(&paddle1);
	drawnObjects.push_back(&scoreBoard.getLeftScore());
	drawnObjects.push_back(&scoreBoard.getRightScore());
	updateObjects.push_back(&newBall);
	updateObjects.push_back(&scoreBoard);
	updateObjects.push_back(&paddle1);
	
	collisionHandler.registerBall(newBall);
	collisionHandler.registerPaddle(paddle1);
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

		//Input

		ICommand* command = nullptr;
		command = inputHandler.handleInput();
		if (command != nullptr)
		{
			command->execute(paddle1); 
		}
	

		//Drawing
		
		for (auto drawnObject = drawnObjects.begin(); drawnObject != drawnObjects.end(); drawnObject++)
		{
			window.draw(**drawnObject);
		}
		for (auto updateObject = updateObjects.begin(); updateObject != updateObjects.end(); updateObject++)
		{
			(*updateObject)->update();
		}
		// end the current frame
		window.display();
		time(&endTime);
		std::this_thread::sleep_for(std::chrono::milliseconds(startTime + Constants::FRAMERATE - endTime)); 
	   
		
	}
	return 0;
}