#include "easyfind.hpp"

int main()
{
	std::vector<int> vector1(10);
	for (int i = 0; i < static_cast<int>(vector1.size()); i++)
	{
		vector1[i] = i;
	}
	try {
	std::cout << easyfind(vector1, 3) << std::endl;
		}
	catch (std::logic_error ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::list<int> lst1;
	for (int i = 0; i < static_cast<int>(vector1.size()); i++)
	{
		lst1.push_back(i+100);
	}
	try {
		std::cout << easyfind(lst1, 106) << std::endl;
	}
	catch (std::logic_error ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}