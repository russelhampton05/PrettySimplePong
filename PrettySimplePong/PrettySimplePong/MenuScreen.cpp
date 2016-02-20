#include "MenuScreen.h"
#include "Constants.h"

MenuScreen::MenuScreen()
{

	if (!font.loadFromFile("timesbd.ttf"))
	{
		if (!font.loadFromFile("C:\Windows\Fonts\Times New Roman\timesbd.ttf"))
		{
			std::cout << "Failed to load font times new roman from  file timesbd.ttf \n Please put the in the same folder as the .exe or in C:\Windows\Fonts";
		}
	}
	
	addColumn("Ball Count", choices.blankTarget, -1);
	addColumn("Ball Speed", choices.blankTarget, -1);
	addColumn("Paddle Side", choices.blankTarget, -1);
	addColumn("Paddle Size", choices.blankTarget, -1);
	addColumn("Background Color", choices.blankTarget, -1);
	addColumn("Start/Restart", choices.start, 0);
	addColumn("Exit ",choices.exit, 0);
	
	addColumn("Press P at any time to pause and ESC to access or leave menu \n Arrow keys move the paddle (up,down,left.right). Highlight start or exit and press enter to select.",choices.blankTarget, -1);
	
	addRow("Paddle Size", "80", choices.paddleSize, 80);
	addRow("Paddle Size", "120",choices.paddleSize, 120);
	addRow("Paddle Size", "160", choices.paddleSize, 160);

	addRow("Background Color", "Blue", choices.bgColor,0);
	addRow("Background Color", "Black", choices.bgColor,1);
	addRow("Background Color", "Red", choices.bgColor,2);

	addRow("Paddle Side", "Left",choices.paddleSide, 0);
	addRow("Paddle Side", "Right", choices.paddleSide, 1);

	addRow("Ball Speed", "10", choices.ballSpeed, 10);
	addRow("Ball Speed", "12", choices.ballSpeed, 12);
	addRow("Ball Speed", "14", choices.ballSpeed, 14);
	addRow("Ball Speed", "16", choices.ballSpeed, 16);


	addRow("Ball Count", "1", choices.numBalls, 1);
	addRow("Ball Count", "2", choices.numBalls, 2);
	addRow("Ball Count", "3", choices.numBalls, 3);
	addRow("Ball Count", "4", choices.numBalls, 4);
	addRow("Ball Count", "Kyle's Mode", choices.numBalls, 15);
	
	menuItems[0][0].setSelected(true);

	for (int i = 0; i < menuItems.size(); i++)
	{
		if (menuItems[i].size()>1)
		{
			menuItems[i][1].setSelected(true);
		}
	}

}


MenuScreen::~MenuScreen()
{
}

int MenuScreen::Run(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		//SFML ques up events. This goes through all of them and checks for button presses or window closes.
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
					return Constants::GAME_SCREEN;
				}
				else if (event.key.code == sf::Keyboard::Key::Return)
				{
					if (choices.start >= 0)
					{
						return Constants::RESET_GAMESCREEN;
					}
					else if (choices.exit >= 0)
					{
						exit(1);
					}	
				}
				else
				{
					handleInput(event.key.code);
				}
				break;



			}
		}
		window.clear(sf::Color::Black);
		draw(window);
		window.display();
	}
	return 0;
}
void MenuScreen::draw(sf::RenderWindow &window)
{
	int xSpacing = 0;
	int ySpacing = 0;
	for (auto columnIterator = menuItems.begin(); columnIterator != menuItems.end(); columnIterator++)
	{
		for (auto rowIterator = columnIterator->begin(); rowIterator != columnIterator->end(); rowIterator++)
		{
			rowIterator->getText().setPosition(xSpacing, ySpacing);
			window.draw(rowIterator->getText());
			if (xSpacing == 0)
			{
				xSpacing = xSpacing + 200;
			}
			xSpacing = xSpacing + 100;

		}
		xSpacing = 0;
		ySpacing = ySpacing + 50;
	}
}

//as input is detected, we check to see where our menu currently is and then
//update highlighter position as well as apply the relevent values to the menu choices class.
void MenuScreen::handleInput(sf::Keyboard::Key key)
{
	choices.start = -1;
	choices.exit = -1;
	switch (key)
	{
	case sf::Keyboard::Key::Up: moveUp(); break;
	case sf::Keyboard::Key::Down: moveDown(); break;
	case sf::Keyboard::Key::Right: moveRight(); break;
	case sf::Keyboard::Key::Left: moveLeft(); break;
	}
}
void MenuScreen::moveUp()
{
	for (auto column = menuItems.begin(); column != menuItems.end(); column++)
	{
		if ((*column)[0].getSelected())
		{
			if (column != menuItems.begin())
			{
				(*column)[0].setSelected(false);
				--column;
				(*column)[0].setSelected(true);
				(*column)[0].applyAssignedValue();
				
				break;
			}
		}
	}
}
void MenuScreen::moveDown()
{

	for (auto column = menuItems.begin(); column != menuItems.end(); column++)
	{
		if ((*column)[0].getSelected())
		{
			if (column != --menuItems.end())
			{
				(*column)[0].setSelected(false);
				++column;
				(*column)[0].setSelected(true);
				(*column)[0].applyAssignedValue();
				break;
			}
		}
	}
}
void MenuScreen::moveRight()
{
	for (auto column = menuItems.begin(); column != menuItems.end(); column++)
	{
		if ((*column)[0].getSelected())
		{
			for (auto row = ++column->begin(); row != column->end(); row++)
			{
				if ((*row).getSelected())
				{
					if (row != --column->end())
					{
						row->setSelected(false);
						++row;
						row->setSelected(true);
						row->applyAssignedValue();
					}
				}
			}
		}
	}
}
void MenuScreen::moveLeft()
{
	for (auto column = menuItems.begin(); column != menuItems.end(); column++)
	{
		if ((*column)[0].getSelected())
		{
			for (auto row = ++column->begin(); row != column->end(); row++)
			{
				if ((*row).getSelected())
				{
					if (row != ++column->begin())
					{
						row->setSelected(false);
						--row;
						row->setSelected(true);
						row->applyAssignedValue();
					}
				}
			}
		}
	}
}