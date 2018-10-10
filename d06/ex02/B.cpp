#include "B.hpp"

B::B(void)
{
	return;
}

B::B(B &c)
{
	*this = c;
	return;
}

B::~B(void)
{
	return;
}

B &B::operator=(B const &ref) 
{
	static_cast<void>(ref);
	return (*this);
}