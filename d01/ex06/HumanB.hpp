#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB();
	
		std::string name;
		Weapon	*gun;
		void attack();
		void setWeapon(Weapon &wep);
};

#endif