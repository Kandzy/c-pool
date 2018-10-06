#ifndef PARAMETRS_HPP
#define PARAMETRS_HPP

#define PLAYER_SHIP 1;
#define ENEMY_SHIP 11;
#define AMMO 111;

# include <ncurses.h>

class Parametrs
{
	private:
		unsigned int 	_HP;
		unsigned int 	_lives;
		unsigned int 	_type;
		std::string 	_name;
	public:
		Parametrs();
		~Parametrs();
};

#endif