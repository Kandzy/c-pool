#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    return ;
}

ZombieEvent::~ZombieEvent()
{
    return ;
}

void ZombieEvent::setZombieType(str type)
{
    this->_type = type;
    return ;
}

Zombie *ZombieEvent::newZombie(str name)
{
    return (new Zombie(_type, name));
}

Zombie *ZombieEvent::randomChump(void)
{
    str names[] = {"El Diablo", "Tham Kench", "Liorik", "Urgot", "Sion"};
    int     index = rand() % 5;
    Zombie  *zombie;
    
    if (this->_type == "")
    {
        this->setZombieType("walking");
    }
    zombie = this->newZombie(names[index]);
    zombie->announce();
    return (zombie);
}