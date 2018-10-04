#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <cstdlib>
# include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent();
    ~ZombieEvent();
    void        setZombieType(str);
    Zombie      *newZombie(str);
    Zombie      *randomChump(void);

private:
    str  _type;
};

#endif