#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon &gun);
		~HumanA();
	
		std::string name;
		Weapon	&wep;
		void attack();
};

#endif