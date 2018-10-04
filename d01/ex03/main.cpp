#include "ZombieHorde.hpp"

int main()
{
	ZombieHorde LichKing = ZombieHorde(5);
	LichKing.announce();
	ZombieHorde theLichKing = ZombieHorde(20);
	theLichKing.announce();
	ZombieHorde theLichKing2 = ZombieHorde(-10);
	theLichKing2.announce();
	ZombieHorde theLichKing3 = ZombieHorde(0);
	theLichKing3.announce();
	ZombieHorde theLichKing4 = ZombieHorde(1);
	theLichKing4.announce();
	ZombieHorde theLichKing5 = ZombieHorde(-1);
	theLichKing5.announce();
	return (0);
}