#include "GameScreen.h"



GameScreen::~GameScreen()
{
}

int GameScreen::Run(sf::RenderWindow &window)
{

//sf::RenderWindow window(sf::VideoMode(Constants::windowXSize, Constants::windowYSize), "PSPong");

time_t startTime;
time_t endTime;

bool paused = false;
sf::Font pauseFont;
sf::Text pauseText;
if (!pauseFont.loadFromFile("timesbd.ttf"))
{
	if (!pauseFont.loadFromFile("C:\Windows\Fonts\Times New Roman\timesbd.ttf"))
	{
		std::cout << "Failed to load font times new roman from  file timesbd.ttf \n Please put the in the same folder as the .exe or in C:\Windows\Fonts";
	}
}

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
		if (event.type == sf::Event::Closed)
			window.close();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		paused = !paused;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
		if (paused)
		{
			window.clear(sf::Color::Black);
			window.draw(pauseText);
			
			window.display();
		}
	}


	if (!paused)
	{

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
	

}
gameObjects.deleteObjects();
return 0;
	
}