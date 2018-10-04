#include "Human.hpp"

int	main(void)
{
	Human 		attack;
	std::string wep;
	std::string	target;

	target = "Anduin";
	std::cout << "Melee attack!" << std::endl;
	attack.action("mAttack", target);
	std::cout << std::endl;

	target = "Griefer in minecraft";
	std::cout << "Range attack!" << std::endl;
	attack.action("rAttack", target);
	std::cout << std::endl;

	target = "Alduin";
	std::cout << "Shout!" << std::endl;
	attack.action("shout", target);
	return (0);
}