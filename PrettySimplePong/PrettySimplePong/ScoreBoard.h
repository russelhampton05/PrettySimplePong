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
		if (!textFont.loadFromFile("BAUHS93.TTF"))
		{
			std::cout << "Font failed to load, text won't appear \n";
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

	void onNotify(Constants::WallHit);
	void update();
};

