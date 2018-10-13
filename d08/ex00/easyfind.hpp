#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
int		easyfind(T &cont, int val)
{
	typename T::iterator 	iterator;
	int						i = 0;
	for (iterator = cont.begin(); iterator != cont.end(); ++iterator)
	{
		if (*iterator == val)
			return i;
		i++;
	}
	throw std::logic_error("Value not found.");
	return (-1);
}

#endif