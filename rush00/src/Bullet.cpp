#include "../includes/Bullet.hpp"

Bullet::Bullet()
{
	return;
}

Bullet::Bullet(int x, int y, int type) : Parametrs(type, '-')
{
	this->_type = type;
	if(type == PLAYER_SHIP)
	{
		this->_speed = 100;
		this->_col = x + 1;
	} else 
	{
		this->_speed = 5000;
		this->_col = x - 1;
	}
	this->_row = y;
	this->oldmove = clock();
}

Bullet::Bullet(const Bullet &spship)
{
	*this = spship;
}

int Bullet::getRow()
{
	return this->_row;
}

int Bullet::getCol()
{
	return this->_col;
}

void Bullet::move()
{
	unsigned long long now = clock();
	double sec = now - oldmove;
	if (sec > this->_speed)
	{
		this->oldmove = now;
		if (this->_type == PLAYER_SHIP)
		{
			if (this->_col < 198)
			{
				this->_col++;
			}
		}
		else if (this->_type == ENEMY_SHIP)
		{
			if (this->_col > 1)
			{
				this->_col--;
			}
		}
	}
}

unsigned int Bullet::getSymb()
{
	return this->_objChar;
}

Bullet::~Bullet()
{
	return;
}

Bullet &Bullet::operator= (const Bullet &bullet)
{
	if(this != &bullet)
	{
		this->_speed = bullet._speed;
	}
	return (*this);
}

void	Bullet::setCol(unsigned int col)
{
	this->_col = col;
}

void	Bullet::setRow(unsigned int row)
{
	this->_row = row;
}
