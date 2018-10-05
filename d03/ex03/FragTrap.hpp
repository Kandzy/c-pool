#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "ClapTrap.hpp"
// #include <unistd.h>

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &ft);
		virtual ~FragTrap();
		FragTrap &operator=(FragTrap const &ft);
	

		void vaulthunter_dot_exe(std::string const & target);
		void GandhiAttack(std::string const & target);
		void feministsAttack(std::string const & target);
		void rageStathamAttack(std::string const & tagret);
		void JohnCenaAttack(std::string const & tagret);
		void BiberAttack(std::string const & target);
};

#endif