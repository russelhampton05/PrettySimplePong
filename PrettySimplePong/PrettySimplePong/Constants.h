#pragma once
#ifndef Constants_H
#define Constants_H
#include "SFML\Window\Keyboard.hpp"
namespace Constants
{
	const int FRAMERATE = 30;
	const int BALLSIZE = 15;
	const int START_X = 80;
	const int START_Y = 80;
	const int windowXSize = 400;
	const int windowYSize = 400;
	const int PADDLE_LENGTH = 80;
	const int PADDLE_WIDTH = 10;
	const int PADDLE_A = 10;
	const int TEXT_SIZE = 15;
	const int PADDLE_V = 30;
	const int PADDLE_F = 7;
	const int EMPTY = 9001; //What does the scouter say about his power level?
	const sf::Keyboard::Key MOVE_UP = sf::Keyboard::Key::Up;
	const sf::Keyboard::Key MOVE_DOWN = sf::Keyboard::Key::Down;		
	const sf::Keyboard::Key MOVE_LEFT = sf::Keyboard::Key::Left;
	const sf::Keyboard::Key MOVE_RIGHT = sf::Keyboard::Key::Right;
	enum WallHit  { LEFT, RIGHT, UP, DOWN };
}

#endif