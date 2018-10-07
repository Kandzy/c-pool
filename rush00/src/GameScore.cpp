#include "../includes/GameScore.hpp"

GameScore::GameScore()
{
	this->_gameScore = 0;
}

GameScore::GameScore(const GameScore &gscore)
{
	*this = gscore;
}

GameScore::~GameScore()
{
	return ;
}

GameScore &GameScore::operator= (const GameScore &gscore)
{
	if (this != &gscore)
		this->_gameScore = gscore.getGameScore();
	return (*this);
}

int		GameScore::getGameScore(void) const
{
	return this->_gameScore;
}

void	GameScore::setGameScore(unsigned int gs)
{
	this->_gameScore = gs;
}

void GameScore::displayGameScore(unsigned int sec, WINDOW *scoreWin, SpaceShip const &ship)
{
	mvwprintw(scoreWin, 1, 1, 
		"Score: %4d || Live: %d || Time from start: %0.2d:%0.2d", 
		this->_gameScore, ship.getLives(),
		sec / 60, sec % 60);
}
