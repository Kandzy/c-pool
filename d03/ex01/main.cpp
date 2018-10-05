#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// FragTrap a;
	// FragTrap b(a);
	FragTrap c("Walle");
	FragTrap d("Useless");
	FragTrap h(d);
	ScavTrap scav("Pilov");
	ScavTrap pal("Arthas");
	ScavTrap lk("Arthas the Lich King");
	ScavTrap g(scav);

	pal = lk;

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

	scav.challengeNewcomer();
	scav.rangeAttack("");
	scav.meleeAttack("");
	scav.meleeAttack("MY neighbours");
	scav.rangeAttack("Gandi");
	scav.takeDamage(1);
	scav.takeDamage(3);
	scav.takeDamage(10);
	scav.takeDamage(2148);
	scav.beRepaired(3);
	scav.beRepaired(50);
	scav.beRepaired(4000);
		
	return (0);
}