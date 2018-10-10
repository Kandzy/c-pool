#include "C.hpp"

C::C(void)
{
	return;
}

C::C(C &c)
{
	*this = c;
	return;
}

C::~C(void)
{
	return;
}

C &C::operator=(C const &ref) 
{
	static_cast<void>(ref);
	return (*this);
}