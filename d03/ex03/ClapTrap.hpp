#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
// #include <unistd.h>

class ClapTrap{
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
		ClapTrap();
		ClapTrap(std::string name, int HP, int maxHP, int SP, int maxSP, int level, int meleeAD, int rangeAD, int armor);
		ClapTrap(ClapTrap const &ft);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &ft);
		void rangeAttack(std::string const &target);
		void meleeAttack(std::string const &target);
		void takeDamage(unsigned int damage);
		void beRepaired(unsigned int amount);
		void setCharacteristic(int HP, int maxHP, int SP, int maxSP, int level, int meleeAD, int rangeAD, int armor);

		int	getHP() const;
		int	getMaxHP() const;
		int	getSP() const;
		int	getMaxSP() const;
		int	getLevel() const;
		int	getMeleeAD() const;
		int	getRangeAD() const;
		int	getArmor() const;
		std::string	getName() const;
		void setHP(int value);
		void setMaxHP(int value);
		void setSP(int value);
		void setMaxSP(int value);
		void setLevel(int value);
		void setMeleeAD(int value);
		void setRangeAD(int value);
		void setArmor(int value);
		void setName(std::string value);
};

#endif