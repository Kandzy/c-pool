#ifndef	BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
	private:
		const void *_addr;
	public:
		Brain();
		~Brain();
		const void *identify();
};

#endif