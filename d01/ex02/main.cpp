#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int
main(void)
{
    Zombie  *Rick;
    Zombie  *Morty;
    Zombie  *Sylvana;
    ZombieEvent zEvent;

    zEvent.setZombieType("UNDEAD");
    Rick = zEvent.randomChump();
    Rick->announce();
    delete Rick;
    zEvent.setZombieType("TANK");
    Morty = zEvent.randomChump();
    Morty->announce();
    delete Morty;
    zEvent.setZombieType("ASSASIN");
    Sylvana = zEvent.randomChump();
    Sylvana->announce();
    delete Sylvana;
    return (0);
}