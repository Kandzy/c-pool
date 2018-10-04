#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &gun) : wep(gun)
{
	this->name = name;
	return ;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->wep.getType() << std::endl;
}

HumanA::~HumanA()
{
	return ;
}