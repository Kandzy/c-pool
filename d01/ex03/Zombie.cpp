#include "Zombie.hpp"

Zombie::Zombie()
{
    return ;
}

Zombie::Zombie(str type, str name)
{
	this->type = type;
	this->name = name;
    return ;
}
Zombie::~Zombie()
{
    return ;
}

void Zombie::announce()
{
    str message;
    if (this->name == "Arthas")
    {
        message = "Rise and serve your king!";
    }
    else
    {
        message = "For the Lich King";
    }
    str scream = "<" + this->name + " (" + this->type + ")> " + message;
    pout << (scream) << nl;
}
