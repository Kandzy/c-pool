#include "../includes/SpaceShip.hpp"
#include "../includes/GameLogic.hpp"

SpaceShip::SpaceShip() : Parametrs(ENEMY_SHIP, '&'), nextS(NULL), prevS(NULL)
{
	struct timeval times;

	gettimeofday(&times, NULL);
	srand((times.tv_sec * 10) + (times.tv_usec * 10) + 1);
	this->_row = rand() % (MAX_Y - MIN_Y);
	this->_col = MAX_X - 2;
}

SpaceShip::SpaceShip(unsigned int type) : Parametrs(type, '>'), nextS(NULL), prevS(NULL)
{
	if (type == ENEMY_SHIP)
	{
		this->_objChar = '&';
	}
	this->_lives = 3;
	this->_type = type;
	this->_col = MIN_X + 5;
	this->_row = MAX_Y / 2;
}

SpaceShip::SpaceShip(const SpaceShip &spship)
{
	*this = spship;
}

void SpaceShip::setPosition(int x, int y)
{
	if (this->_col >= MIN_X - (unsigned int)x && this->_col < MAX_X - (unsigned int)x)
	{
		this->_col += x;
	}
	if (this->_row >= MIN_Y - (unsigned int)y && this->_row < MAX_Y - (unsigned int)y)
	{
		this->_row += y;
	}
}

void SpaceShip::setLives(unsigned int lives)
{
	this->_lives = lives;
}

SpaceShip::~SpaceShip()
{
	if (this->bul)
	{
		delete this->bul;
	}
}

int SpaceShip::getRow()
{
	return this->_row;
}

int SpaceShip::getCol()
{
	return this->_col;
}

unsigned int SpaceShip::getSymb()
{
	return this->_objChar;
}

SpaceShip &SpaceShip::operator=(SpaceShip const &spship)
{
	if(this != &spship)
	{
		this->_lives = spship._lives;
	}
	return (*this);
}

Bullet		*SpaceShip::createBullet(void)
{
	Bullet *bullet = new Bullet(this->_col, this->_row, this->_type);
	return bullet;
}
