#include <iostream>
#include "OfficeBlock.hpp"

// ShrubberyCreationForm (Required grades : sign 145, exec 137). Action : Create
// a file called <target>_shrubbery, and write ASCII trees inside it, in the current
// directory.
// • RobotomyRequestForm (Required grades : sign 72, exec 45). Action : Makes some
// drilling noises, and tells us that <target> has been robotomized successfully 50%
// of the time. the rest of times, tells us it’s a failure.
// • PresidentialPardonForm (Required grades : sign 25, exec 5). Action : Tells us
// <target> has been pardoned by Zaphod Beeblebrox.

	// "Presidential pardon"

	// "Robotomy request"
	
	//  "Shrubbery creation"

int main(void)
{
	std::cout << std::endl << "\033[1;32mNormal Test\033[0m" << std::endl << std::endl;

	OfficeBlock *littleOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Bob", 130)), *(new Bureaucrat("Tom", 130)));
	try{
	littleOffice->doBureaucracy("Shrubbery creation", "Jhon Cena");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption Form Test\033[0m" << std::endl << std::endl;

	OfficeBlock *oneMoreOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Jerry", 150)), *(new Bureaucrat("Mark", 130)));
	try{
		oneMoreOffice->doBureaucracy("Shrubbery cration", "Undertaker");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption low grade execute Test\033[0m" << std::endl << std::endl;
	
	OfficeBlock *twoMoreOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Kerry", 100)), *(new Bureaucrat("Mark", 150)));
	try{
		twoMoreOffice->doBureaucracy("Shrubbery creation", "Undertaker");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption no executor Test\033[0m" << std::endl << std::endl;

	Bureaucrat *b = NULL;
	OfficeBlock *threeMoreOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Sara", 100)), *b);
	try{
		threeMoreOffice->doBureaucracy("Shrubbery creation", "Undertaker");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption no signer Test\033[0m" << std::endl << std::endl;

	OfficeBlock *fourMoreOffice = new OfficeBlock(*(new Intern()), *b, *b);
	try{
		fourMoreOffice->doBureaucracy("Shrubbery creation", "Undertaker");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption no intern Test\033[0m" << std::endl << std::endl;

	Intern *a = NULL;
	OfficeBlock *fiveMoreOffice = new OfficeBlock(*a, *b, *b);
	try{
		fiveMoreOffice->doBureaucracy("Shrubbery creation", "Undertaker");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mNormal robotomy Test\033[0m" << std::endl << std::endl;

	OfficeBlock *sixMoreOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Zed", 60)), *(new Bureaucrat("Ivern", 40)));
	try{
		sixMoreOffice->doBureaucracy("Robotomy request", "Rick");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mNormal robotomy Test 2\033[0m" << std::endl << std::endl;

	OfficeBlock *sevenMoreOffice = new OfficeBlock(*(new Intern()), *(new Bureaucrat("Ahri", 22)), *(new Bureaucrat("Lux", 5)));
	try{
		sevenMoreOffice->doBureaucracy("Robotomy request", "Xayah");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mNormal Pardon Test \033[0m" << std::endl << std::endl;

	try{
		sevenMoreOffice->doBureaucracy("Presidential pardon", "Morty");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption Pardon Test \033[0m" << std::endl << std::endl;

	try{
		sixMoreOffice->doBureaucracy("Presidential pardon", "Morty");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mExeption Pardon Test 2\033[0m" << std::endl << std::endl;

	try{
		littleOffice->doBureaucracy("Presidential pardon", "Morty");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;32mNormal Shrubbery creation Test 2\033[0m" << std::endl << std::endl;

	try{
		sixMoreOffice->doBureaucracy("Shrubbery creation", "Morty");
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}