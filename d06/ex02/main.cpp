#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#include <iostream>

Base * generate(void)
{
	srand(clock());
	int index = rand() % 3;
	Base *base[3] = {new A(), new B(), new C()};
	return (base[index]);
}

void			identify_from_reference(Base &p)
{
	if (dynamic_cast<A*>(&p))
	{
		std::cout << "\033[1;35mA\033[0m" << std::endl;
	}
	else if (dynamic_cast<B*>(&p))
	{
		std::cout << "\033[1;35mB\033[0m" << std::endl;
	}
	else if (dynamic_cast<C*>(&p))
	{
		std::cout << "\033[1;35mC\033[0m" << std::endl;
	}
}

void			identify_from_pointer(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "\033[1;35mA\033[0m" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "\033[1;35mB\033[0m" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "\033[1;35mC\033[0m" << std::endl;
	}
}

int		main()
{
	std::cout << "\033[1;34mGenerating random instanse of A B OR C class.\033[0m" << std::endl;
	Base	*base = generate();

	std::cout << "\033[1;32mLets try identify class with a pointer: \033[0m";
	identify_from_pointer(base);

	std::cout << "\033[1;32mLets try identify class with a reference: \033[0m";
	identify_from_reference(*base);

	delete base;

	return (0);
}