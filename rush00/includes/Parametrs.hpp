#ifndef PARAMETRS_HPP
# define PARAMETRS_HPP

# define PLAYER_SHIP 1
# define ENEMY_SHIP 2
// # define PLAYER_BULLET 2
// # define ENEMY_BULLET 4

# include <ncurses.h>
# include <iostream>

class Parametrs
{
	protected:
		unsigned int 	_HP;
		unsigned int 	_lives;
		unsigned int 	_type;
		std::string 	_name;
		double			_speed;
		unsigned int	_objSize;
		unsigned int	_objChar;
		unsigned int	_col;
		unsigned int	_row;

	public:
		Parametrs();
		Parametrs(unsigned int type, char c);
		Parametrs(const Parametrs &gscore);
		~Parametrs();
		Parametrs &operator= (const Parametrs &params);
		unsigned int		getHP(void) const;
		unsigned int		getLives(void) const;
		unsigned int		getType(void) const;
		std::string			getName(void) const;
		unsigned int		getSpeed(void) const;
		unsigned int		getObjSize(void) const;
		unsigned int		getObjChar(void) const;
		unsigned int		getCol(void) const;
		unsigned int		getRow(void) const;
};

#endif