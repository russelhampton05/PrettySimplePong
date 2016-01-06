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

	addColumn("Ball Count");
	addColumn("Ball Speed");
	addColumn("Paddle Side");
	addColumn("Background Color");
	addColumn("Restart");
	addColumn("Exit");

	addColumn("Press P at any time to pause and ESC to access or leave menu");
	

	addRow("Background Color", "Blue");
	addRow("Background Color", "Black");
	addRow("Background Color", "Red");

	addRow("Paddle Side", "Left");
	addRow("Paddle Side", "Right");

	addRow("Ball Speed", "10");
	addRow("Ball Speed", "15");
	addRow("Ball Speed", "20");
	addRow("Ball Speed", "25");


	addRow("Ball Count", "1");
	addRow("Ball Count", "2");
	addRow("Ball Count", "3");
	addRow("Ball Count", "4");
	
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

void MenuScreen::handleInput(sf::Keyboard::Key key)
{
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
					}
				}
			}
		}
	}
}