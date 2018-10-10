#include "StringConvertor.hpp"
#include <string>
#include <iomanip>

int		main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Only 1 argument required!" << std::endl;
		return (0);
	}
	std::cout << std::fixed << std::setprecision(1);
	StringConvertor *convert = new StringConvertor(argv[1]);

	std::cout << "Char: ";

	try{
		int	charDispCheck = static_cast<int>(*convert);
		if (charDispCheck < 33 || charDispCheck > 126)
		{
			std::cout << "Non displayable" << std::endl;
		}
		else 
		{
			std::cout << static_cast<char>(*convert) << std::endl;
		}
	} catch (StringConvertor::StringConversionExeption &exeption)
	{
		std::cout << exeption.what() << std::endl;
	}

	std::cout << "Int: ";

	try{
		std::cout << static_cast<int>(*convert) << std::endl;
	} catch(StringConvertor::StringConversionExeption &exeption)
	{
		std::cout << exeption.what() << std::endl;
	}

	std::cout << "Float: ";

	try{
		std::cout << static_cast<float>(*convert) << "f" << std::endl;
	} catch(StringConvertor::StringConversionExeption &exeption)
	{
		std::cout << exeption.what() << std::endl;
	}

	std::cout << "Double: ";

	try{
		std::cout << static_cast<double>(*convert) << std::endl;
	} catch(StringConvertor::StringConversionExeption &exeption)
	{
		std::cout << exeption.what() << std::endl;
	}

	return (0);
}