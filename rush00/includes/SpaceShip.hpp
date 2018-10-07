#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <iostream>
#include "Parametrs.hpp"
#include "Bullet.hpp"
#include <sys/time.h>

class SpaceShip : public Parametrs
{
	private:
		unsigned int 	_type;

	public:
		SpaceShip();
		SpaceShip(unsigned int type);
		SpaceShip(const SpaceShip &spship);
		virtual ~SpaceShip();
		SpaceShip &operator= (const SpaceShip &spship);
		int getRow();
		int getCol();
		unsigned int getSymb();
		Bullet		*bul;
		Bullet		*createBullet(void);
		void		setPosition(int x, int y);
		void		setLives(unsigned int HP);
		SpaceShip *nextS;
		SpaceShip *prevS;
};

#endif
