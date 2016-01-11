#pragma once
#include "IScreen.h"
#include <string>
#include <vector>
#include <iostream>
#include "menuChoices.h"
class MenuScreen :
	public IScreen
{
	//information holding class. Represents an item on the menu.
	class MenuItem
	{
	private:
		bool selected;
		std::string stringValue;
		double value;
		sf::Text text;
		int *assignedValue;

	public:
		MenuItem()
		{
			selected = false;
			stringValue = "";
			value = 0.0;
			assignedValue = nullptr;
			text.setCharacterSize(16);
		}
		void setValue(double other)
		{
			value = other;
		}
		void setAssignedValue(int& value)
		{
			assignedValue = &value;
		}
		void applyAssignedValue()
		{
			*assignedValue = value;
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
	
	std::vector<std::vector<MenuItem>> menuItems;

	
 menuChoices choices;

public:
	MenuScreen();
	~MenuScreen();

	menuChoices& getChoices()
	{
		return choices;
	}
	//target is the menuChoice value which is bound
	void addColumn(std::string stringValue, int& target, int value)
	{
		MenuItem newItem;
		newItem.getText().setFont(font);
		newItem.setAssignedValue(target);
		
		newItem.setValue(value);

		newItem.setString(stringValue);
		std::vector<MenuItem> newColumn;
		newColumn.push_back(newItem);
		menuItems.push_back(newColumn);
	}
	//Searches for column and then adds itself to it. 
	void addRow(std::string columnName, std::string text, int& target, int value)
	{
		MenuItem item;
		item.setString(text);
		item.setAssignedValue(target);
		item.getText().setFont(font);
		item.setValue(value);

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

