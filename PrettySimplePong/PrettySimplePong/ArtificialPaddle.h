#pragma once
#include "IBallObserver.h"
class Paddle;
class Ball;
class InputHandler;
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
	
	
	void setPaddle(Paddle& paddle)
	{
		this->paddle = &paddle;
	}
	void onNotify(const Ball*);
	void setInput(InputHandler& other)
	{
		inputHandler = &other;
	}
	void makeMove();
};

