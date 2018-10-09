#include <iostream>
#include "CentralBureaucracy.hpp"


int main(void)
{
	struct timeval times;
	gettimeofday(&times,NULL);
	srand((times.tv_sec) + (times.tv_usec));
	CentralBureaucracy	cb;
	
	// try{
		
	for (int i = 0; i < OFFICES / 2; i++)
	{
		std::string exec = "PlanktonExecuter";
		std::string sign = "PlanktonSigner";
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		int	grade = rand() % 150 + 1;
		exec.push_back(i+48);
		cb.feedExecutor(*new Bureaucrat(exec, grade));
		usleep(2);
		gettimeofday(&times,NULL);
		srand((times.tv_sec) + (times.tv_usec));
		grade = rand() % 150 + 1;
		sign.push_back(i+48);
		cb.feedSigner(*new Bureaucrat(sign, grade));
	}
	for (int j = 0; j < QUEUE; j++)
	{
		std::string rage = "RagedGrandma";
		rage.push_back(j + 32);
		cb.queueUp(rage);
	}
	cb.doBureaucracy();
	// } catch (std::exception &ex)
	// {
	// 	std::cout << ex.what() << std::endl;
	// }
	return 0;
}