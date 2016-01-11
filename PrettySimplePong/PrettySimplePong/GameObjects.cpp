#include "GameObjects.h"
#include "ICommand.h"
#include "InputHandler.h"
#include "menuChoices.h"

GameObjects::~GameObjects()
{
	deleteObjects();
}

void GameObjects::addPlayerPaddle(Constants::WallSide side, int ID,double length)
{
	Paddle* newPaddle = new Paddle(side, *choices);
	newPaddle->setLength(length);
	newPaddle->setCollisionHandler(collisionHandler);
	collisionHandler.registerPaddle(*newPaddle);
	newPaddle->setID(ID);
	drawnObjects.push_back(newPaddle);
	updateObjects.push_back(newPaddle);
	paddles.push_back(newPaddle);
}
void GameObjects::giveCommand(int ID, ICommand& command)
{
	for (auto paddle = paddles.begin(); paddle != paddles.end(); ++paddle)
	{
		if ((*paddle)->getID() == ID)
		{
			command.execute(*(*paddle));
		}
	}
}
void GameObjects::addBall(double x, double y, double velocity)
{
	Ball* newBall = new Ball(x,y, velocity);
	newBall->setCollisionHandler(collisionHandler);
	collisionHandler.registerBall(*newBall);
	newBall->addWallObserver(scoreBoard);
	for (auto aiPlayer = aiPlayers.begin(); aiPlayer != aiPlayers.end(); ++aiPlayer)
	{
		newBall->addBallObserver(*(*aiPlayer));
	}
	drawnObjects.push_back(newBall);
	updateObjects.push_back(newBall);
	balls.push_back(newBall);
}
void GameObjects::addAiPaddle(Constants::WallSide side, double length)
{
	ArtificialPaddle* newAi = new ArtificialPaddle(*commands);
	Paddle* newPaddle = new Paddle(side, *choices);
	newPaddle->setLength(length);
	newPaddle->setCollisionHandler(collisionHandler);
	collisionHandler.registerPaddle(*newPaddle);
	
	drawnObjects.push_back(newPaddle);
	updateObjects.push_back(newPaddle);

	newAi->setPaddle(*newPaddle);
	newAi->setInput(*commands);
	for (auto ball = balls.begin(); ball != balls.end(); ++ball)
	{
	(*ball)->addBallObserver(*newAi);
	}

	aiPlayers.push_back(newAi);
}
void GameObjects::aiMakeMove()
{
	for (auto aiPlayer = aiPlayers.begin(); aiPlayer != aiPlayers.end(); ++aiPlayer)
	{
		(*aiPlayer)->makeMove();
	}
}
void GameObjects::update()
{
	for (auto updateObject = updateObjects.begin(); updateObject != updateObjects.end(); updateObject++)
	{
		(*updateObject)->update();
	}
}

void GameObjects::deleteObjects()
{
	
	for (auto iterator = paddles.begin(); iterator != paddles.end(); ++iterator)
	{
		if ((*iterator))
		{
			delete (*iterator);
			(*iterator) = nullptr;
		}
	}
	for (auto iterator = balls.begin(); iterator != balls.end(); ++iterator)
	{
		if ((*iterator))
		{
			delete (*iterator);
			(*iterator) = nullptr;
		}
	}
	for (auto iterator = aiPlayers.begin(); iterator != aiPlayers.end(); ++iterator)
	{
		if ((*iterator))
		{
			delete (*iterator);
			(*iterator) = nullptr;
		}
	}

	paddles.clear();
	balls.clear();
	aiPlayers.clear();
}