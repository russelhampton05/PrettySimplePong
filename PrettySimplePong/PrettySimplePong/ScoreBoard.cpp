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

void ScoreBoard::onNotify(Constants::WallHit side)
{
	if (side == Constants::WallHit::LEFT)
	{
		rightCount++;
	}
	if (side == Constants::WallHit::RIGHT)
	{
		leftCount++;
	}
}