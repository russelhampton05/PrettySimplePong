#pragma once
#include "Constants.h"

//Meant to hold the values that will be selected in the menu
class menuChoices
{
public:
	menuChoices()
	{
		numBalls = 1;
		ballSpeed = 10;
		paddleSide = 0;
		bgColor = 0;
		paddleSize = 80;
		exit = -1;
		start = -1;
	}
	~menuChoices();
	int exit;
	int start;
	int numBalls;
	int paddleSide;
	int ballSpeed;
	int bgColor;
	int blankTarget;
	int paddleSize;
};

