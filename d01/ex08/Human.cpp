#include "Human.hpp"

void Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack on " + target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack on " + target << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Fus Ro Dah on " + target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	void (Human::*func[])(std::string const &target) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string move[] = {"mAttack", "rAttack", "shout"};

	for (int i = 0; i < 3; i++)
	{
		if (move[i] == action_name)
		{
			(this->*func[i])(target);
			break ;
		}	
	}
}