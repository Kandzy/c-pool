#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _HP(100), _maxHP(100), _SP(50), _maxSP(50), _level(1), _name("ClapTrap(Default)"), _meleeAD(30), _rangeAD(20), _armor(5)
{
	std::cout << "Parent default constructor has been called. Name of new Trap is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name, int HP, int maxHP, int SP, int maxSP, int level, int meleeAD, int rangeAD, int armor) : _HP(HP), _maxHP(maxHP), _SP(SP), _maxSP(maxSP), _level(level), _name(name), _meleeAD(meleeAD), _rangeAD(rangeAD), _armor(armor)
{
	std::cout << "Parent Constructor has been called. Name of new Trap is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &st)
{
	*this = st;
	std::cout << "Trap was copied... Name of this unit is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Your unit Trap \""+ this->_name +"\" was destroyed. You can buy new Trap for a 200$!" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &st)
{
	std::cout << "Your Trap \"" + this->_name + "\" where uptated to ";
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
	std::cout << "Trap \"" + this->_name + "\". Good Luck!" << std::endl;
	return (*this);
}

void ClapTrap::rangeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your Trap \"" + this->_name + "\" attacks " + enemy + " with range attack! " +
	enemy + " was damaged by " << this->_rangeAD << " points!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your Trap \"" + this->_name + "\" attacks " + enemy + " with melee attack! " +
	enemy + " was damaged by " << this->_meleeAD << " points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	int trueDmg = damage - this->_armor;
	if (trueDmg < 0)
		trueDmg = 0;
	if ((this->_HP = this->_HP - trueDmg) < 0)
	{
		this->_HP = 0;
		std::cout << "Critical damage " << trueDmg << "! HP: " << this->_HP << "." << std::endl
		 << "Your Trap \"" + this->_name + "\" in critical state! Pleas Repair robot befor continue!" <<std::endl;
		return ;
	}
	std::cout << "Careful! Your Trap \"" + this->_name + "\" get damaged for " << trueDmg << " points!" << std::endl << " HP: " << this->_HP << "." << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->_HP = this->_HP + amount) > this->_maxHP)
	{
		this->_HP = this->_maxHP;
		std::cout <<  "Your Trap \"" + this->_name + "\" fully repaired!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
	}
	std::cout <<  "Your Trap \"" + this->_name + "\" was repaired for "<< amount<<" points!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
}

/*
 * Standart getters and Setters
 */

int	ClapTrap::getHP() const
{
	return (this->_HP);
}
int	ClapTrap::getMaxHP() const
{
	return (this->_maxHP);
}
int	ClapTrap::getSP() const
{
	return (this->_SP);
}

int	ClapTrap::getMaxSP() const
{
	return (this->_maxSP);
}

int	ClapTrap::getLevel() const
{
	return (this->_level);
}

int	ClapTrap::getMeleeAD() const
{
	return (this->_meleeAD);
}

int	ClapTrap::getRangeAD() const
{
	return (this->_rangeAD);
}

int	ClapTrap::getArmor() const
{
	return (this->_armor);
}

std::string	ClapTrap::getName() const
{
	return (this->_name);
}

void	ClapTrap::setHP(int value)
{
	this->_HP = value;
}
void	ClapTrap::setMaxHP(int value)
{
	this->_maxHP = value;
}
void	ClapTrap::setSP(int value)
{
	this->_SP = value;
}

void	ClapTrap::setMaxSP(int value)
{
	this->_maxSP = value;
}

void	ClapTrap::setLevel(int value)
{
	this->_level = value;
}

void	ClapTrap::setMeleeAD(int value)
{
	this->_meleeAD = value;
}

void	ClapTrap::setRangeAD(int value)
{
	this->_rangeAD = value;
}

void	ClapTrap::setArmor(int value)
{
	this->_armor = value;
}

void	ClapTrap::setName(std::string value)
{
	this->_name = value;
}