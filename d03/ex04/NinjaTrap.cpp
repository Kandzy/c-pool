#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap("FragTrap(Default)", 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "Default constructor has been called. Name of new FR4G-TP is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "Constructor has been called. Name of new FR4G-TP is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

NinjaTrap::NinjaTrap(NinjaTrap const &ft)
{
	*this = ft;
	std::cout << "FR4G-TP was copied... Name of this unit is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "Your unit FR4G-TP \""+this->getName() +"\" was destroyed. You can buy new FR4G-TP for a 200$!" << std::endl;
	return ;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &ft)
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

void NinjaTrap::ninjaShoebox(const FragTrap &obj)
{
	std::cout << "Hello my friend FragTrap " + obj.getName() + " let me tell you little story ..." << std::endl;
}
void NinjaTrap::ninjaShoebox(const ScavTrap &obj)
{
	std::cout << "Hello my friend ScavTrap " + obj.getName() + " let me tell you little story ..." << std::endl;
}
void NinjaTrap::ninjaShoebox(const ClapTrap &obj)
{
	std::cout << "Hello my friend ClapTrap " + obj.getName() + " let me tell you little story ..." << std::endl;
}
void NinjaTrap::ninjaShoebox(const NinjaTrap &obj)
{
	std::cout << "Hello my friend NinjaTrap " + obj.getName() + " let me tell you little story ..." << std::endl;
}
