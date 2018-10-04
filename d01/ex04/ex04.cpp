#include <iostream>
#include <string>

int	main() 
{
	std::string		msg = "HI THIS IS BRAIN";
	std::string 	*pMsg = &msg;
	std::string		&rMsg = msg;
	
	std::cout << *pMsg << std::endl;
	std::cout << rMsg << std::endl;
	return (0);
}