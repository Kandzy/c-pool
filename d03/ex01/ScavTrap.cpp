#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : _HP(100), _maxHP(100), _SP(50), _maxSP(50), _level(1), _name("ScavTrap(ScavTrap)"), _meleeAD(20), _rangeAD(15), _armor(3)
{
	std::cout << "Default constructor has been called. Name of new ScavTrap is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : _HP(100), _maxHP(100), _SP(50), _maxSP(50), _level(1), _name(name), _meleeAD(20), _rangeAD(15), _armor(3)
{
	std::cout << "Constructor has been called. Name of new ScavTrap is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &st)
{
	*this = st;
	std::cout << "ScavTrap was copied... Name of this unit is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Your unit ScavTrap \""+ this->_name +"\" was destroyed. You can buy new ScavTrap for a 200$!" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &st)
{
	std::cout << "Your ScavTrap \"" + this->_name + "\" where uptated to ";
	if (this != &st)
	{
		this->_HP = st.getHP();
		this->_maxHP = st.getMaxHP();
		this->_SP = st.getSP();
		this->_maxSP = st.getMaxSP();
		this->_level = st.getLevel();
		this->_name = st.getName();
		this->_rangeAD = st.getRangeAD();
		this->_meleeAD = st.getMeleeAD();
		this->_armor = st.getArmor();
	}
	std::cout << "ScavTrap \"" + this->_name + "\". Good Luck!" << std::endl;
	return (*this);
}

void ScavTrap::rangeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your ScavTrap \"" + this->_name + "\" attacks " + enemy + " with range attack! " +
	enemy + " was damaged by " << this->_rangeAD << " points!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your ScavTrap \"" + this->_name + "\" attacks " + enemy + " with melee attack! " +
	enemy + " was damaged by " << this->_meleeAD << " points!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int damage)
{
	int trueDmg = damage - this->_armor;
	if (trueDmg < 0)
		trueDmg = 0;
	if ((this->_HP = this->_HP - trueDmg) < 0)
	{
		this->_HP = 0;
		std::cout << "Critical damage " << trueDmg << "! HP: " << this->_HP << "." << std::endl
		 << "Your ScavTrap \"" + this->_name + "\" in critical state! Pleas Repair robot befor continue!" <<std::endl;
		return ;
	}
	std::cout << "Careful! Your ScavTrap \"" + this->_name + "\" get damaged for " << trueDmg << " points!" << std::endl << " HP: " << this->_HP << "." << std::endl;
	return;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if ((this->_HP = this->_HP + amount) > this->_maxHP)
	{
		this->_HP = this->_maxHP;
		std::cout <<  "Your ScavTrap \"" + this->_name + "\" fully repaired!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
	}
	std::cout <<  "Your ScavTrap \"" + this->_name + "\" was repaired for "<< amount<<" points!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
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
	std::cout << "ScavTrap " + this->_name + " preparing challenge!" << std::endl;
	std::cout << "***********************NEW CHALLENGE*********************" << std::endl;
	std::cout << ">> "<< challenge[index] << std::endl;
	std::cout << "***********************END CHALLENGE*********************" << std::endl;
	return ;
}

/*
 * Standart getters
 */

int	ScavTrap::getHP() const
{
	return (this->_HP);
}
int	ScavTrap::getMaxHP() const
{
	return (this->_maxHP);
}
int	ScavTrap::getSP() const
{
	return (this->_SP);
}

int	ScavTrap::getMaxSP() const
{
	return (this->_maxSP);
}

int	ScavTrap::getLevel() const
{
	return (this->_level);
}

int	ScavTrap::getMeleeAD() const
{
	return (this->_meleeAD);
}

int	ScavTrap::getRangeAD() const
{
	return (this->_rangeAD);
}

int	ScavTrap::getArmor() const
{
	return (this->_armor);
}

std::string	ScavTrap::getName() const
{
	return (this->_name);
}