#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

# include <string>
# include <cstdlib>
# include "Zombie.hpp"

class ZombieHorde {
	public:
		ZombieHorde(int amount);
		~ZombieHorde();
		
		void announce();
		str randName();

	private:
		int _amount;
		Zombie *_zArmy;
		bool Arthas;
};

#endif