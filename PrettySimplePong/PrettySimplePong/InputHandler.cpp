#include "InputHandler.h"
#include "SFML\Window\Keyboard.hpp"
#include "Constants.h"

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}


ICommand* InputHandler::handleInput()
{
	ICommand* commandPressed = nullptr;
	if (sf::Keyboard::isKeyPressed(Constants::MOVE_LEFT) && sf::Keyboard::isKeyPressed(Constants::MOVE_DOWN))
	{
		return moveLeftDown;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_LEFT) && sf::Keyboard::isKeyPressed(Constants::MOVE_UP))
	{
		return moveLeftUp;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_RIGHT) && sf::Keyboard::isKeyPressed(Constants::MOVE_UP))
	{
		return moveRightUp;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_RIGHT) && sf::Keyboard::isKeyPressed(Constants::MOVE_DOWN))
	{
		return moveRightDown;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_DOWN))
	{
		return moveDown;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_UP))
	{
		return moveUp;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_LEFT))
	{
		return moveLeft;
	}
	else if (sf::Keyboard::isKeyPressed(Constants::MOVE_RIGHT))
	{
		return moveRight;
	}
	else
	{
		return noCommand;
	}
	

}