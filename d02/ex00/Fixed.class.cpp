#include "Fixed.class.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
	return ;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

int  Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_fixedPoint = raw;
	return;
}

Fixed &Fixed::operator=(Fixed const  &fix)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->_fixedPoint = fix.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}