#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	SuperTrap supertr("NAGIBATOR666");
	supertr.beRepaired(5);
	supertr.BiberAttack("gogo");
	supertr.meleeAttack("WHOIS");
	ClapTrap c;
	supertr.ninjaShoebox(c);
	return (0);
}