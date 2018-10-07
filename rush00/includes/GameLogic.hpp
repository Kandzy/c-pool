#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include <ncurses.h>
# include <iostream>
# include <unistd.h>
# include "GameScore.hpp"
# include "SpaceShip.hpp" 

# define WIN_HEIGHT 200
# define WIN_WIDTH 50
# define MAX_X 199
# define MAX_Y 49
# define MIN_X 1
# define MIN_Y 1
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Q 113
# define KEY_SPACE 32

class GameLogic{
	private:
		WINDOW		*_win;
		WINDOW		*_score;
		GameScore	*_gScore;
		SpaceShip	*_pShip;
		int			_ch;
		size_t		spawnTime;
		size_t toEnemyMoveStart;
		SpaceShip	*enemySpawn();
		void		keyManip();

	public:
		GameLogic();
		GameLogic(GameLogic const &gl);
		GameLogic	&operator=(GameLogic const &gl);
		~GameLogic();

		void	gameStart();
		void	enemyShipMove(SpaceShip *enemy, size_t enemyMoveEnd);
		
		
};

#endif
