#pragma once
#include "IBallObserver.h"
class Paddle;
class Ball;
class InputHandler;
//Owns a paddle and decided what input it should get.
//The AI gives the same commands a user would give. 
class ArtificialPaddle : public IBallObserver
{
private:
	double distanceToPaddle(sf::Vector2f);
	Paddle* paddle;
	const Ball* closestBall;
	InputHandler* inputHandler;
public:
	ArtificialPaddle(InputHandler&);
	~ArtificialPaddle();
	void onNotify(const Ball*);
	
	void setPaddle(Paddle& paddle)
	{
		this->paddle = &paddle;
	}
	
	void setInput(InputHandler& other)
	{
		inputHandler = &other;
	}
	void makeMove();
};

