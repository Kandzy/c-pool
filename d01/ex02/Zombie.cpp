#include "Zombie.hpp"

Zombie::Zombie(str type, str name)
{
	this->_type = type;
	this->_name = name;
    return ;
}
Zombie::~Zombie()
{
    return ;
}

void Zombie::announce()
{
    str scream = "<" + this->_name + " (" + this->_type + ")> " + 
	"Eat braaaaaaiiiiinnnssssss ... Om nom nom ...";
    pout << (scream) << nl;
}