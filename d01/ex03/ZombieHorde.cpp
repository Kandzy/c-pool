#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int amount)
{
	if (amount >= 0)
	{
		this->_zArmy = new Zombie[amount];
		this->_amount = amount;
		for(int i = 0; i < amount; i++)
		{
			this->_zArmy[i].name = this->randName();
			if (this->_zArmy[i].name == "Arthas")
			{
				this->_zArmy[i].type = "Lich King";
			}
			else
			{
				this->_zArmy[i].type = "Undead";
			}
		}
	}
	else {
		this->_amount = 0;
	}
	return;
}

ZombieHorde::~ZombieHorde()
{
	if (this->_amount > 0)
	{
		delete [] this->_zArmy;
	}
	pout << "Fall of the lich king." << nl;
	return ;
}

str ZombieHorde::randName()
{
 	str names[] = {"Arthas", "banshee", "ghoul", "butcher", "lich"};
    int     index = rand() % 5;
	if (names[index] == "Arthas" && this->Arthas)
	{
		index = index + 1;
	}
	if (names[index] == "Arthas")
	{
		this->Arthas = true;
	}
    return (names[index]);
}

void ZombieHorde::announce()
{
    for(int i = 0; i < this->_amount; i++)
	{
		this->_zArmy[i].announce();
	}
}