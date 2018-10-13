#include "span.hpp"

int	main(){
	Span a(10);
	int b = a.longestSpan();
	std::cout << "Longest span: " << b  << std::endl;
	a.addNumber(5);
	b = a.shortestSpan();
	std::cout << "Shortest span: " << b << std::endl;
	a.addNumber(20);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(3);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(-5);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(-7);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(25);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(1000);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(1001);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(0);
	a.addNumber(0);
	std::cout << "Longest span: " << a.longestSpan() << std::endl;
	std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
	a.addNumber(3232);
	Span lol(50);
	for (int i = 0; i < 30; i++)
	{
		lol.addNumber(i);
	}
	std::vector<int> vec;
	for (int i = 0; i < 20; i++)
		vec.push_back(i);
	std::cout << "iterator addNumber start" << std::endl;
	lol.addNumber(vec.begin(), vec.end());
	std::cout << "iterator addNumber end" << std::endl;
	return (0);
}