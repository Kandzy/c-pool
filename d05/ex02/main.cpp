#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat *b1 = new Bureaucrat("Ali", 40);
	RobotomyRequestForm *f1 = new RobotomyRequestForm("Chuck Norris");
	b1->signForm(*f1);
	b1->executeForm(*f1);

	std::cout << std::endl;

	Bureaucrat *b2 = new Bureaucrat("Lolec", 100);
	RobotomyRequestForm *f2 = new RobotomyRequestForm("Enemy");
	b2->signForm(*f2);
	b2->executeForm(*f2);

	std::cout << std::endl;

	Bureaucrat *b3 = new Bureaucrat("Kid", 1);
	PresidentialPardonForm *f3 = new PresidentialPardonForm("Teacher");
	b3->signForm(*f3);
	b3->executeForm(*f3);

	std::cout << std::endl;

	Bureaucrat *b4 = new Bureaucrat("Lowkick", 10);
	PresidentialPardonForm *f4 = new PresidentialPardonForm("Jerry");
	b4->signForm(*f4);
	b4->executeForm(*f4);

	std::cout << std::endl;

	Bureaucrat *b5 = new Bureaucrat("NB4", 130);
	ShrubberyCreationForm *f5 = new ShrubberyCreationForm("List");
	b5->signForm(*f5);
	b5->executeForm(*f5);
		
	std::cout << std::endl;

	try{
		Bureaucrat *b6 = new Bureaucrat("NB5", 150);
		ShrubberyCreationForm *f6 = new ShrubberyCreationForm("List2");
		b6->signForm(*f6);
		b6->executeForm(*f6);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat *b7 = new Bureaucrat("NB6", 160);
		ShrubberyCreationForm *f7 = new ShrubberyCreationForm("List3");
		b7->signForm(*f7);
		b7->executeForm(*f7);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat *b8 = new Bureaucrat("NB7", -4);
		ShrubberyCreationForm *f8 = new ShrubberyCreationForm("List3");
		b8->signForm(*f8);
		b8->executeForm(*f8);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}