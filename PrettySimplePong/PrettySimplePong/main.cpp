#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include "IUpdatable.h"
#include "Ball.h"
//Define these in ini file later//

int main()
{ 
	//std::vector<
	sf::RenderWindow window(sf::VideoMode(800, 600), "PSPong");
	time_t startTime;
	time_t endTime;
	std::vector<sf::Drawable*> drawnObjects;
	std::vector<IUpdatable*> updateObjects;
	Ball newBall;
	drawnObjects.push_back(&newBall);
	updateObjects.push_back(&newBall);
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

		//Game Logic

		//process Input
		//Update Players

		 
		window.clear(sf::Color::Blue);
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