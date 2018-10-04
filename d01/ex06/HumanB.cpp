#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	return ;
}

void HumanB::setWeapon(Weapon &wep)
{
	this->gun = &wep;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->gun->getType() << std::endl;
}

HumanB::~HumanB()
{
	return ;
}