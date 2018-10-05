#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap("SUPERTRIP", 100, 100, 120, 120, 1, 60, 20, 5), FragTrap("SUPERTRIP"), NinjaTrap("SUPERTRIP")
{
	std::cout << "Default constructor of SuperTrap has been called. Name of new SuperTrap is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5), FragTrap(name), NinjaTrap(name)
{
	std::cout << "Constructor of SuperTrap has been called. Name of new SuperTrap is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

SuperTrap::SuperTrap(SuperTrap const &ft)
{
	*this = ft;
	std::cout << "SuperTrap was copied... Name of this unit is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

SuperTrap::~SuperTrap()
{
	std::cout << "Your unit FR4G-TP \""+this->getName() +"\" was destroyed. You can buy new FR4G-TP for a 200$!" << std::endl;
	return ;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &ft)
{
	std::cout << "Your FR4G-TP \"" +this->getName() + "\" where uptated to ";
	if (this != &ft)
	{
		this->setHP(ft.getHP());
		this->setMaxHP(ft.getMaxHP());
		this->setSP(ft.getSP());
		this->setMaxSP(ft.getMaxSP());
		this->setLevel(ft.getLevel());
		this->setName(ft.getName());
		this->setRangeAD(ft.getRangeAD());
		this->setMeleeAD(ft.getMeleeAD());
		this->setArmor(ft.getArmor());
	}
	std::cout << "FR4G-TP \"" +this->getName() + "\". Good Luck!" << std::endl;
	return (*this);
}