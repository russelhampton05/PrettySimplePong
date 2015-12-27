#pragma once
#include "IWallObserver.h"
#include "IUpdatable.h"
#include <iostream>
#include <string>
class ScoreBoard : public IWallObserver, public IUpdatable
{
private:
	sf::Font textFont;
	sf::Text leftScore;
	sf::Text rightScore;

	int leftCount;
	int rightCount;
	

	void initializeText(sf::Text&, int);
public:
	
	
	ScoreBoard()
	{
		if (!textFont.loadFromFile("timesbd.ttf"))
		{
			if (!textFont.loadFromFile("C:\Windows\Fonts\Times New Roman\timesbd.ttf"))
			{
				std::cout << "Failed to load font times new roman from  file timesbd.ttf \n Please put the in the same folder as the .exe or in C:\Windows\Fonts";
			}
		}
	
		initializeText(leftScore, -10);
		initializeText(rightScore, 10);
		leftCount = 0;
		rightCount = 0;

	}
	~ScoreBoard();
	
	sf::Text& getLeftScore()
	{
		return leftScore;
	}

	sf::Text& getRightScore()
	{
		return rightScore;
	}

	void onNotify(Constants::WallSide);
	void update();
};

