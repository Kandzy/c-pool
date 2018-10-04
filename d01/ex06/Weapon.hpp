#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
	private:
		std::string	_type;
	public:
		const std::string &getType();
		void setType(std::string);
};

#endif