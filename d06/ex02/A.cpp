#include "A.hpp"

A::A(void)
{
	return;
}

A::A(A &a)
{
	*this = a;
	return;
}

A::~A(void)
{
	return;
}

A &A::operator=(A const &ref) 
{
	static_cast<void>(ref);
	return (*this);
}