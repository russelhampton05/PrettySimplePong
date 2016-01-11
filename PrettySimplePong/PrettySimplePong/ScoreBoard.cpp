#include "ScoreBoard.h"


//ScoreBoard::ScoreBoard()
//{
//}


ScoreBoard::~ScoreBoard()
{
}


void ScoreBoard::initializeText(sf::Text& score, int x)
{
	
	score.setString("0");
	score.setFont(textFont);
	//This 10 was deemed ok to leave as a "magic number" because it doesn't need to change based on screen size
	score.setPosition((Constants::windowXSize /2) + x, 10); 
	score.setCharacterSize(Constants::TEXT_SIZE);
	score.setColor(sf::Color::White);


}

void ScoreBoard::update()
{
	leftScore.setString(std::to_string(leftCount));
	rightScore.setString(std::to_string(rightCount));
	//possibly end game condition in the future
}

void ScoreBoard::onNotify(Constants::WallSide side)
{
	if (side == Constants::WallSide::LEFT)
	{
		rightCount++;
	}
	if (side == Constants::WallSide::RIGHT)
	{
		leftCount++;
	}
}