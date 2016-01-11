#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "ScoreBoard.h"
#include "InputHandler.h"
#include "ArtificialPaddle.h"
#include "CollisionHandler.h"

class InputHandler;
class menuChoices;
//Stores paddles, aiPaddles, and balls. Also handles their creation.
class GameObjects
{
private:
	std::vector<Ball*> balls;
	std::vector<sf::Drawable*> drawnObjects;
	std::vector<IUpdatable*> updateObjects;
	std::vector<Paddle*> paddles;
	std::vector<ArtificialPaddle*> aiPlayers;
	ScoreBoard scoreBoard;
	CollisionHandler collisionHandler;
	InputHandler* commands;
	menuChoices* choices;
public:
	GameObjects(InputHandler& handler, menuChoices& choices)
	{
		this->choices = &choices;
		commands = &handler;
		updateObjects.push_back(&scoreBoard);
		drawnObjects.push_back(&scoreBoard.getLeftScore());
		drawnObjects.push_back(&scoreBoard.getRightScore());
	}
	~GameObjects();
	void addPlayerPaddle(Constants::WallSide, int ID, double);
	void addBall(double x, double y, double);
	void addAiPaddle(Constants::WallSide, double);
	void aiMakeMove();
	void update();
	void giveCommand(int, ICommand&);
	void deleteObjects();
	std::vector<IUpdatable*> getUpdatables()
	{
		return updateObjects;
	}
	std::vector<sf::Drawable*> getDrawables()
	{
		return drawnObjects;
	}
	std::vector<Ball*> getBalls()
	{
		return  balls;
	}
	std::vector<Paddle*> getPaddle()
	{
		return paddles;
	}
};

