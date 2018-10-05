#include "FragTrap.hpp"

FragTrap::FragTrap() : _HP(100), _maxHP(100), _SP(100), _maxSP(100), _level(1), _name("FR4G-TP(FragTrap)"), _meleeAD(30), _rangeAD(20), _armor(5)
{
	std::cout << "Default constructor has been called. Name of new FR4G-TP is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : _HP(100), _maxHP(100), _SP(100), _maxSP(100), _level(1), _name(name), _meleeAD(30), _rangeAD(20), _armor(5)
{
	std::cout << "Constructor has been called. Name of new FR4G-TP is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &ft)
{
	*this = ft;
	std::cout << "FR4G-TP was copied... Name of this unit is \"" + this->_name + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Your unit FR4G-TP \""+ this->_name +"\" was destroyed. You can buy new FR4G-TP for a 200$!" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &ft)
{
	std::cout << "Your FR4G-TP \"" + this->_name + "\" where uptated to ";
	if (this != &ft)
	{
		this->_HP = ft.getHP();
		this->_maxHP = ft.getMaxHP();
		this->_SP = ft.getSP();
		this->_maxSP = ft.getMaxSP();
		this->_level = ft.getLevel();
		this->_name = ft.getName();
		this->_rangeAD = ft.getRangeAD();
		this->_meleeAD = ft.getMeleeAD();
		this->_armor = ft.getArmor();
	}
	std::cout << "FR4G-TP \"" + this->_name + "\". Good Luck!" << std::endl;
	return (*this);
}

void FragTrap::rangeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your FR4G-TP \"" + this->_name + "\" attacks " + enemy + " with range attack! " +
	enemy + " was damaged by " << this->_rangeAD << " points!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << "Good! Your FR4G-TP \"" + this->_name + "\" attacks " + enemy + " with melee attack! " +
	enemy + " was damaged by " << this->_meleeAD << " points!" << std::endl;
}

void FragTrap::takeDamage(unsigned int damage)
{
	int trueDmg = damage - this->_armor;
	if (trueDmg < 0)
		trueDmg = 0;
	if ((this->_HP = this->_HP - trueDmg) < 0)
	{
		this->_HP = 0;
		std::cout << "Critical damage " << trueDmg << "! HP: " << this->_HP << "." << std::endl
		 << "Your FR4G-TP \"" + this->_name + "\" in critical state! Pleas Repair robot befor continue!" <<std::endl;
		return ;
	}
	std::cout << "Careful! Your FR4G-TP \"" + this->_name + "\" get damaged for " << trueDmg << " points!" << std::endl << " HP: " << this->_HP << "." << std::endl;
	return;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if ((this->_HP = this->_HP + amount) > this->_maxHP)
	{
		this->_HP = this->_maxHP;
		std::cout <<  "Your FR4G-TP \"" + this->_name + "\" fully repaired!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
	}
	std::cout <<  "Your FR4G-TP \"" + this->_name + "\" was repaired for "<< amount<<" points!" << std::endl
		<< "HP:" << this->_HP << std::endl;
		return;
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->_SP >= 25)
	{
		struct timeval times;
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		int     index = rand() % 5;
		void (FragTrap::*pfunc[])(std::string const &) = {&FragTrap::GandhiAttack, &FragTrap::feministsAttack, &FragTrap::rageStathamAttack, &FragTrap::JohnCenaAttack, &FragTrap::BiberAttack};
		std::cout << "FR4G-TP " + this->_name + " prepeare something for your enemy!" << std::endl;
		std::cout << "*******************************************************************";
		(this->*pfunc[index])(target);
		this->_SP -= 25;
		std::cout << "*******************************************************************" << std::endl;
		std::cout << "I think that robot little bit broken ... " << std::endl << "Robot Energy: " << this->_SP << "/" << this->_maxSP << std::endl << std::endl;
		return ;
	}
	else {
		std::cout << "Your FR4G-TP out of energy! Energy: " << this->_SP << "/" << this->_maxSP << std::endl << std::endl;
	}
}

void FragTrap::GandhiAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl <<"FR4G-TP \"" + this->_name + "\" summun rage Mohandas Karamchand Gandhi with rage variable value 255!" +
	enemy + " was damaged for 2147483647 points with nuclear bomb! Be aware of rage Gandhi!!! RUN FOR YOUR LIVES!!!!" << std::endl;
	return ;
}

void FragTrap::feministsAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl << "FR4G-TP \"" + this->_name + "\" summon 10 feminists!!! Your enemy "+enemy
	+" damaged for 0 points but now game developers under attack!! NOOOO!! HELP THEM!!! SAVE OUR GAMES FROM FEMINISTS!!!!" << std::endl;
	return ;
}

void FragTrap::rageStathamAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl << "FR4G-TP \"" + this->_name + "\" call Jason Statham!!! Jason Statham \
hurt his little finger on the bedside table and ready to kill your enemy! " + enemy + " was damaged for 1488 points!" << std::endl;
	return ;
}

void FragTrap::JohnCenaAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl << "WATCHOUT WATCHOUT WATCHOUT, HIS NAME IS JOHN CENA! Tu tudu tuuuuuuu, tu tudu tuuuuuuu!! Jogn Cena Back Slamed "+ enemy + " for 50 points!!" << std::endl;
	return ;
}

void FragTrap::BiberAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl << "OH NO!!! DONT DO IT FR4G-TP \"" + this->_name + "\" DONT!!!! PLEASE!!!! "<< std::endl
	<< "*FR4G-TP turned on Bieber music* " << std::endl
	<< "Your ears bleeding and " + enemy + " got 0 damage cause (he/she/it) loves Biber music!!!" << std::endl;
	return ;
}


/*
 * Standart getters
 */

int	FragTrap::getHP() const
{
	return (this->_HP);
}
int	FragTrap::getMaxHP() const
{
	return (this->_maxHP);
}
int	FragTrap::getSP() const
{
	return (this->_SP);
}

int	FragTrap::getMaxSP() const
{
	return (this->_maxSP);
}

int	FragTrap::getLevel() const
{
	return (this->_level);
}

int	FragTrap::getMeleeAD() const
{
	return (this->_meleeAD);
}

int	FragTrap::getRangeAD() const
{
	return (this->_rangeAD);
}

int	FragTrap::getArmor() const
{
	return (this->_armor);
}

std::string	FragTrap::getName() const
{
	return (this->_name);
}