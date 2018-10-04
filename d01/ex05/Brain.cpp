#include "Brain.hpp"

Brain::Brain()
{
	this->_addr = this;
}

const void *Brain::identify()
{
	return this->_addr;
}

Brain::~Brain() 
{
	return;
}
