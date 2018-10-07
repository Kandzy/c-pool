#ifndef GAMESCORE_CPP
# define GAMESCORE_CPP

# include <iostream>
#include "SpaceShip.hpp"

class	GameScore
{
	private:
		int		_gameScore;

	public:
		GameScore();
		GameScore(const GameScore &gscore);
		~GameScore();
		GameScore &operator= (const GameScore &gscrore);
		int		getGameScore(void) const;
		void	setGameScore(unsigned int gs);
		void	displayGameScore(unsigned int sec, WINDOW *scoreWin, SpaceShip const &ship);
};

#endif
