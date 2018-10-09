#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat *bur = new Bureaucrat("Anastasia", 40);
	try{
		Form form("newForm", 40, 40);
		bur->signForm(form);
	}
	catch(std::exception &ex)
	{
		std::cout<< ex.what() << std::endl;
	}
	Bureaucrat *bur2 = new Bureaucrat("Vlad", 149);
	try{
		Form form2("TrueForm", 30, 30);
		bur2->signForm(form2);
	}
	catch(std::exception &ex)
	{
		std::cout<< ex.what() << std::endl;
	}
	return 0;
}