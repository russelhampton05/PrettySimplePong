#pragma once
#ifndef Constants_H
#define Constants_H
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Window\VideoMode.hpp"
namespace Constants
{
	const int BALL_VELOCITY_X = 5;
	const int BALL_VELOCITY_Y = 4;
	const int BALL_MIN_VELOCITY = 4;
	
	const float FRICTION = .025;
	const int GAME_SCREEN = 0;
	const int RESET_GAMESCREEN = 2;
	const int MENU_SCREEN = 1;
	const int PADDLE_VELOCITY_X = 8;
	const int PADDLE_VELOCITY_Y = 8;
	const int FRAMERATE = 12;
	const int BALLSIZE = 15;
	const int windowXSize = sf::VideoMode::getDesktopMode().width/3 * 2;
	const int windowYSize = (sf::VideoMode::getDesktopMode().height / 3)*2;
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


	const sf::Keyboard::Key MOVE_UP2 = sf::Keyboard::Key::W;
	const sf::Keyboard::Key MOVE_DOWN2 = sf::Keyboard::Key::S;
	const sf::Keyboard::Key MOVE_LEFT2 = sf::Keyboard::Key::A;
	const sf::Keyboard::Key MOVE_RIGHT2 = sf::Keyboard::Key::D;
	enum WallSide  { LEFT, RIGHT, UP, DOWN };
	enum BackgroundColor {BLUE, BLACK, RED};
}

#endif