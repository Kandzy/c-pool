#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern *littleKid = new Intern();
	Form *f1 = littleKid->makeForm("Presidential pardon", "bocal");
	std::cout << *f1 << std::endl << std::endl;
	Form *f2 = littleKid->makeForm("Shrubbery creation", "List");
	std::cout << *f2 << std::endl << std::endl;
	Form *f3 = littleKid->makeForm("Robotomy request", "Bender");
	std::cout << *f3 << std::endl << std::endl;
	Form *f4 = littleKid->makeForm("Unknown form", "Me");
	std::cout << f4 << std::endl;
	return 0;
}