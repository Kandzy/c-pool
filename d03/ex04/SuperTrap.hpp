#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
// #include <unistd.h>

class SuperTrap : public FragTrap, public NinjaTrap{
	public:
		SuperTrap();
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const &ft);
		virtual ~SuperTrap();
		SuperTrap &operator=(SuperTrap const &ft);
};

#endif