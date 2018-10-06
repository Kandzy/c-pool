#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

class GameLogic{
	public:
		GameLogic();
		GameLogic(GameLogic const &gl);
		GameLogic	&operator=(GameLogic const &gl);
		~GameLogic();

		void gameStart();
		
};

#endif