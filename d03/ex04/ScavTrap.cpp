#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap(Default)", 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "Default constructor has been called. Name of new ScavTrap is \"" + this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3)
{
	std::cout << "Constructor has been called. Name of new ScavTrap is \"" + this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &st)
{
	*this = st;
	std::cout << "ScavTrap was copied... Name of this unit is \"" + this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Your unit ScavTrap \""+ this->getName() +"\" was destroyed. You can buy new ScavTrap for a 200$!" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &st)
{
	std::cout << "Your ScavTrap \"" + this->getName() + "\" where uptated to ";
	if (this != &st)
	{
		this->setHP(st.getHP());
		this->setMaxHP(st.getMaxHP());
		this->setSP(st.getSP());
		this->setMaxSP(st.getMaxSP());
		this->setLevel(st.getLevel());
		this->setName(st.getName());
		this->setRangeAD(st.getRangeAD());
		this->setMeleeAD(st.getMeleeAD());
		this->setArmor(st.getArmor());
	}
	std::cout << "ScavTrap \"" + this->getName() + "\". Good Luck!" << std::endl;
	return (*this);
}

void ScavTrap::challengeNewcomer()
{
	struct timeval times;
	gettimeofday(&times,NULL);
	srand((times.tv_sec) + (times.tv_usec));
	int     index = rand() % 5;
	std::string challenge[] = {
	"FLOR IS LAVA!!",
	"Ice Bucket Challenge! Get ready to cold water!!",
	"Get a tig by flipping the bottle on the table in front of bocal!",
	"Win a duel with Chuck norris!",
	"End the Dark Souls 3 for 42 minutes!"
	};
	std::cout << "ScavTrap " + this->getName() + " preparing challenge!" << std::endl;
	std::cout << "***********************NEW CHALLENGE*********************" << std::endl;
	std::cout << ">> "<< challenge[index] << std::endl;
	std::cout << "***********************END CHALLENGE*********************" << std::endl;
	return ;
}