#include "Intern.hpp"

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern const &in)
{
	*this = in;
	return;
}

Intern &Intern::operator=(Intern const &in)
{
	(void)in;
	return (*this);
}

Form	*Intern::makeForm(std::string const name, std::string const target)
{
	Form	*form = NULL;

	if ((name == "Presidential pardon"))
	{
		form = new PresidentialPardonForm(target);
	}
	else if (name == "Robotomy request")
	{
		form = new RobotomyRequestForm(target);
	}
	else if (name == "Shrubbery creation")
	{
		form = new ShrubberyCreationForm(target);
	}
	else
	{
		std::cout << "Intern don't know how to create " + name + " form!" << std::endl;
		return NULL;
	}

	std::cout << "Intern after 20 hours create " + name + " form!" << std::endl;
	return form;
}

Intern::~Intern(void)
{
	return;
}