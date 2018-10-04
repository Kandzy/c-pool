#include "Sed.class.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Error : only 3 params required (filename, word_to_find, word_to_replace)." << std::endl;
		return (0);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cout << "Error : empty parameter word_to_find or word_to_replace." << std::endl;
		return (0);
	}
	std::string toFind = av[2];
	std::string toReplace = av[3];
	if (!toFind.compare(toReplace))
	{
		std::cout << "Error : parametrs word_to_find and word_to_replace are equal." << std::endl;
		return (0);
	}
	Sed *sed = new Sed(av[1], toFind, toReplace);
	sed->stringReplace();
	delete sed;
	return (0);
}