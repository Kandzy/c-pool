#ifndef INTENT_HPP
#define INTENT_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
								Intern(void);
								Intern(Intern const & in);
								Intern &operator=(Intern const &in);
		Form					*makeForm(std::string name, std::string target);
		virtual					~Intern(void);
};

#endif