#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
// #include <unistd.h>

class NinjaTrap : public ClapTrap{
	public:
		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &ft);
		virtual ~NinjaTrap();
		NinjaTrap &operator=(NinjaTrap const &ft);

		void ninjaShoebox(const FragTrap &ft);
		void ninjaShoebox(const ScavTrap &ft);
		void ninjaShoebox(const ClapTrap &ft);
		void ninjaShoebox(const NinjaTrap &ft);
};

#endif