#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap(Default)", 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "Default constructor has been called. Name of new FR4G-TP is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "Constructor has been called. Name of new FR4G-TP is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &ft)
{
	*this = ft;
	std::cout << "FR4G-TP was copied... Name of this unit is \"" +this->getName() + "\". Good Luck!" << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Your unit FR4G-TP \""+this->getName() +"\" was destroyed. You can buy new FR4G-TP for a 200$!" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &ft)
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

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->getSP() >= 25)
	{
		struct timeval times;
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		int     index = rand() % 5;
		void (FragTrap::*pfunc[])(std::string const &) = {&FragTrap::GandhiAttack, &FragTrap::feministsAttack, &FragTrap::rageStathamAttack, &FragTrap::JohnCenaAttack, &FragTrap::BiberAttack};
		std::cout << "FR4G-TP " +this->getName() + " prepeare something for your enemy!" << std::endl;
		std::cout << "*******************************************************************";
		(this->*pfunc[index])(target);
		this->setSP(this->getSP() - 25);
		std::cout << "*******************************************************************" << std::endl;
		std::cout << "I think that robot little bit broken ... " << std::endl << "Robot Energy: " << this->getSP() << "/" << this->getMaxSP() << std::endl << std::endl;
		return ;
	}
	else {
		std::cout << "Your FR4G-TP out of energy! Energy: " << this->getSP() << "/" << this->getMaxSP() << std::endl << std::endl;
	}
}

void FragTrap::GandhiAttack(std::string const & target)
{
	std::string enemy = target;
	if (enemy.empty())
	{
		enemy = "\"Unknown enemy\"";
	}
	std::cout << std::endl <<"FR4G-TP \"" +this->getName() + "\" summun rage Mohandas Karamchand Gandhi with rage variable value 255!" +
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
	std::cout << std::endl << "FR4G-TP \"" +this->getName() + "\" summon 10 feminists!!! Your enemy "+enemy
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
	std::cout << std::endl << "FR4G-TP \"" +this->getName() + "\" call Jason Statham!!! Jason Statham \
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
	std::cout << std::endl << "OH NO!!! DONT DO IT FR4G-TP \"" +this->getName() + "\" DONT!!!! PLEASE!!!! "<< std::endl
	<< "*FR4G-TP turned on Bieber music* " << std::endl
	<< "Your ears bleeding and " + enemy + " got 0 damage cause (he/she/it) loves Biber music!!!" << std::endl;
	return ;
}