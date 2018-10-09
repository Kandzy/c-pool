#include	"CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()
{
	for (int i = 0; i < OFFICES; i++)
	{
		this->_office[i].setIntern(*(new Intern()));
	}
	return;
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &cb)
{
	*this = cb;
	return;
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy const &cb)
{
	Bureaucrat *temp = NULL;
	for (int i = 0; i < OFFICES; i++)
	{
		this->_office[i] = cb._office[i];
		this->_office[i].setIntern(*(new Intern()));
		if (cb._office[i].getExecutor())
		{
			temp = new Bureaucrat(*(cb._office[i].getExecutor()));
			this->_office[i].setExecutor(*temp);
		}
		if (cb._office[i].getSigner())
		{
			temp = new Bureaucrat(*(cb._office[i].getSigner()));
			this->_office[i].setSigner(*temp);
		}
	}
	for(int i = 0; i < QUEUE; i++)
	{
		this->_queue[i] = cb._queue[i];
	}
	return *this;
}

void			CentralBureaucracy::feedExecutor(Bureaucrat &executor)
{
	for (int i = 0; i < OFFICES; i++)
	{	
		if(!(this->_office[i].getExecutor()))
		{
			this->_office[i].setExecutor(executor);
			return;
		}
	}
	std::cout << "We have enough executors now. Come later please!" << std::endl;
}

void			CentralBureaucracy::feedSigner(Bureaucrat &signer)
{
	for (int i = 0; i < OFFICES; i++)
	{	
		if(!(this->_office[i].getSigner()))
		{
			this->_office[i].setSigner(signer);
			return;
		}
	}
	std::cout << "We have enough signers now. Come later please!" << std::endl;
}

void			CentralBureaucracy::queueUp(std::string	name)
{
	for(int i = 0; i < QUEUE; i++)
	{
		if (this->_queue[i].empty())
		{
			this->_queue[i] = name;
			return;
		}
	}
	std::cout << "The queue is full! Please wait until the place becomes free." << std::endl;
	return ;
}

void			CentralBureaucracy::doBureaucracy(){
	std::string forms[] = {
		"Robotomy request",
		"Presidential pardon",
		"Shrubbery creation"
	};
	for (int i = 0; i < QUEUE; i++)
	{
		if (!(this->_queue[i].empty()))
		{
			for (int j = 0; j < OFFICES; j++)
			{
				srand(clock());
				int	index = rand() % 3;
				try{
					this->_office[j].doBureaucracy(forms[index], this->_queue[i]);
				}
				catch(std::exception &ex){
					std::cout << ex.what() << std::endl;
				}
				usleep(1000);
			}
		}
	}
	std::cout << std::endl << "\033[1;32m>ALL BUREAUCRACY STAFF DONE!<\033[0m" << std::endl;
}

CentralBureaucracy::~CentralBureaucracy()
{
	return;
}