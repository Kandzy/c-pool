#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define str std::string
# define pout std::cout
# define nl std::endl

class Zombie
{
	public:
		Zombie();
		Zombie(str type, str name);
		~Zombie();
		void announce();

		str type;
		str name;
};

#endif