#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include "IUpdatable.h"
#include "Ball.h"
#include "Paddle.h"
#include "MoveDownCommand.h"
#include "MoveUpCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "InputHandler.h"

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
	InputHandler inputHandler;
	inputHandler.setMoveDown(&moveDownCommand);
	inputHandler.setMoveUp(&moveUpCommand);
	inputHandler.setMoveLeft(&moveLeftCommand);
	inputHandler.setMoveRight(&moveRightCommand);

	Ball newBall;
	Paddle newPaddle;
	drawnObjects.push_back(&newBall);
	drawnObjects.push_back(&newPaddle);
	updateObjects.push_back(&newBall);  
	updateObjects.push_back(&newPaddle);


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
			command->execute(newPaddle);
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