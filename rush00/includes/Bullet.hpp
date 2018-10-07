#ifndef BULLET_HPP
#define BULLET_HPP

#include "Parametrs.hpp"

class Bullet : public Parametrs{
	private:
		unsigned long long	oldmove;
		// int					_exists;

	public:
		int iter;
		Bullet();
		Bullet(int x, int y, int type);
		Bullet(const Bullet &bullet);
		void move();
		int getRow();
		int getCol();
		void	setCol(unsigned int col);
		void	setRow(unsigned int row);
		// void	setExistance(int ex);
		unsigned int getSymb();
		virtual ~Bullet();
		Bullet &operator= (const Bullet &bullet);
};

#endif