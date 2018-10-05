#include "FragTrap.hpp"

int main()
{
	// FragTrap a;
	// FragTrap b(a);
	FragTrap c("Walle");
	FragTrap d("Useless");

	d = c;
	
	c.rangeAttack("");
	c.meleeAttack("");
	c.meleeAttack("MY neighbours");
	c.rangeAttack("Gandi");
	c.vaulthunter_dot_exe("Arnold Schwarzenegger");
	c.takeDamage(1);
	c.takeDamage(3);
	c.takeDamage(10);
	c.takeDamage(2148);
	c.beRepaired(3);
	c.beRepaired(50);
	c.beRepaired(4000);
	return (0);
}