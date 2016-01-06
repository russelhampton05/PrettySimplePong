#pragma once
#include "IScreen.h"
#include <string>
#include <vector>
#include <iostream>
class MenuScreen :
	public IScreen
{
	class MenuItem
	{
	private:
		bool selected;
		std::string stringValue;
		double value;
		sf::Text text;

	public:
		MenuItem()
		{
			selected = false;
			stringValue = "";
			value = 0.0;
		}
		bool getSelected()
		{
			return selected;
		}
		std::string getString()
		{
			return stringValue;
		}
		double getValue()
		{
			return value;
		}
		sf::Text& getText()
		{
			return text;
		}
		void setSelected(bool other)
		{
			selected = other;
			if (selected)
			{
				text.setColor(sf::Color::Red);
			}
			else
			{
				text.setColor(sf::Color::White);
			}
		}
		void setString(std::string other)
		{
			stringValue = other;
			text.setString(other);
			try
			{
				value = std::stod(other);
			}
			catch (std::exception e)
			{
				value = 0.0;
			}
		}
		
	};
private:
	void draw(sf::RenderWindow &window);
	sf::Font font;

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void handleInput(sf::Keyboard::Key);
public:
	MenuScreen();
	~MenuScreen();
	std::vector<std::vector<MenuItem>> menuItems;
	void addColumn(std::string stringValue)
	{
		MenuItem newItem;
		newItem.getText().setFont(font);
		newItem.setString(stringValue);
		std::vector<MenuItem> newColumn;
		newColumn.push_back(newItem);
		menuItems.push_back(newColumn);
	}
	void addRow(std::string columnName,  std::string text)
	{
		MenuItem item;
		item.setString(text);
		
		item.getText().setFont(font);

		for (auto column = menuItems.begin(); column != menuItems.end(); column++)
		{
			if ((*column)[0].getString() == columnName)
			{
				(*column).push_back(item);
				break;
			}
		}
	}
	int Run(sf::RenderWindow &window);
};

