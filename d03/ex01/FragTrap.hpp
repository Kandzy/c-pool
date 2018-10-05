#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
// #include <unistd.h>

class FragTrap{
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
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &ft);
		~FragTrap();
		FragTrap &operator=(FragTrap const &ft);
		void rangeAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int damage);
		void beRepaired(unsigned int amount);

		void vaulthunter_dot_exe(std::string const & target);
		void GandhiAttack(std::string const & target);
		void feministsAttack(std::string const & target);
		void rageStathamAttack(std::string const & tagret);
		void JohnCenaAttack(std::string const & tagret);
		void BiberAttack(std::string const & target);

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