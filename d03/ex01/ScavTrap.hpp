#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
// #include <unistd.h>

class ScavTrap{
	private:
		int	_HP;
		int	_maxHP;
		int	_SP;
		int	_maxSP;
		int	_level;
		std::string _name;
		int	_meleeAD;
		int	_rangeAD;
		int	_armor;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &ft);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &ft);
		void rangeAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int damage);
		void beRepaired(unsigned int amount);

		void challengeNewcomer();

		int	getHP() const;
		int	getMaxHP() const;
		int	getSP() const;
		int	getMaxSP() const;
		int	getLevel() const;
		int	getMeleeAD() const;
		int	getRangeAD() const;
		int	getArmor() const;
		std::string	getName() const;
};

#endif