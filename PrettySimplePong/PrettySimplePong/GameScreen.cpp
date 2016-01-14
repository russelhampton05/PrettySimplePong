#include "GameScreen.h"



GameScreen::~GameScreen()
{
}

int GameScreen::Run(sf::RenderWindow &window)
{
time_t startTime;
time_t endTime;

bool paused = false;



pauseText.setFont(pauseFont);
pauseText.setPosition(window.getSize().x/2, window.getSize().y/2);
pauseText.setString("PAUSED");

//GUI loop
while (window.isOpen())
{
	// check all the window's events that were triggered since the last iteration of the loop
	time(&startTime);

	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: 
			window.close(); 
			break;
		case sf::Event::KeyPressed:
			//access menu
			if (event.key.code == sf::Keyboard::Escape)
			{
				return Constants::MENU_SCREEN;
			}
			break;

		

		}
	}

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		paused = !paused;
		//This just creates a grace period so the user doesn't pause and then immediately unpause
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		if (paused)
		{
			window.clear(BGcolor);
			window.draw(pauseText);
			
			window.display();
		}
	}


	if (!paused)
	{
		window.clear(BGcolor);
		//with the way it is currently set up, you need one input handler per set of key assignments to commands.
		//Right now it's a one player game so this isn't as important. The input handler could also be set to multiple game objects easily.
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
	

}
gameObjects.deleteObjects();
return 0;
	
}

void GameScreen::addBalls()
{
	double startX = Constants::windowXSize/2;
	double startY = Constants::BALLSIZE*2;
	for (int i = 0; i < choices->numBalls; i++)
	{
		gameObjects.addBall(startX, startY, choices->ballSpeed);
		startY = startY + Constants::BALLSIZE*3;
	}
}
void GameScreen::setBGColor()
{
	Constants::BackgroundColor color = (Constants::BackgroundColor)choices->bgColor;
	switch (color)
	{
	case::Constants::BackgroundColor::BLACK: BGcolor = sf::Color::Black; break;
	case::Constants::BackgroundColor::BLUE: BGcolor = sf::Color::Blue; break;
	case::Constants::BackgroundColor::RED: BGcolor = sf::Color::Red; break;
	}
	
}
void GameScreen::addPaddles()
{
	Constants::WallSide aiSide = Constants::WallSide::RIGHT;

	gameObjects.addPlayerPaddle((Constants::WallSide)choices->paddleSide,0, choices->paddleSize);
	if ((Constants::WallSide)choices->paddleSide == Constants::WallSide::RIGHT)
	{
		aiSide = Constants::WallSide::LEFT;
	}
	gameObjects.addAiPaddle(aiSide, choices->paddleSize);

}