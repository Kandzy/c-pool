#include "../includes/Parametrs.hpp"

Parametrs::Parametrs() : _HP(1), _lives(1), _type(ENEMY_SHIP), _objChar('#')
{
	return;
}

Parametrs::Parametrs(unsigned int type, char c) : _HP(1), _lives(1), _type(type), _objChar(c)
{
	return;
}

Parametrs::Parametrs(const Parametrs &param)
{
	*this = param;
}

Parametrs::~Parametrs()
{
	return;
}

Parametrs &Parametrs::operator= (const Parametrs &param)
{
	if (this != &param)
	{
		this->_HP = param.getHP();
		this->_lives = param.getLives();
		this->_type = param.getType();
	}
	return *this;
}

unsigned int		Parametrs::getHP(void) const
{
	return this->_HP;
}

unsigned int		Parametrs::getLives(void) const
{
	return this->_lives;
}

unsigned int		Parametrs::getType(void) const
{
	return this->_type;
}

std::string			Parametrs::getName(void) const
{
	return this->_name;
}

unsigned int		Parametrs::getSpeed(void) const
{
	return this->_speed;
}

unsigned int		Parametrs::getObjSize(void) const
{
	return this->_objSize;
}

unsigned int		Parametrs::getObjChar(void) const
{
	return this->_objChar;
}

unsigned int		Parametrs::getCol(void) const
{
	return this->_col;
}

unsigned int		Parametrs::getRow(void) const
{
	return this->_row;
}
