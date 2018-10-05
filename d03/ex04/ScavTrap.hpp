#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "ClapTrap.hpp"
// #include <unistd.h>

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &ft);
		virtual ~ScavTrap();
		ScavTrap &operator=(ScavTrap const &ft);

		void challengeNewcomer();
};

#endif