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
	if (sf::Keyboard::isKeyPressed(Constants::MOVE_DOWN))
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

}