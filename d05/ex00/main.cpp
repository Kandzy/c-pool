#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *n = new Bureaucrat("Ali", 40);
	std::cout << *n << std::endl;
	try{
		*n += 5;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << *n << std::endl;
	try{
		*n += 50;
	}
	catch (std::exception &ex)
	{
		std::cout << "+50 " << ex.what() << std::endl;
	}
	std::cout << *n << std::endl;
	try {
		*n -= 150;
	}
	catch (std::exception &ex)
	{
		std::cout << "-150 " <<  ex.what() << std::endl;
	}
	std::cout << *n << std::endl;
	return 0;
}