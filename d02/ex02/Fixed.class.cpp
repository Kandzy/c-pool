#include "Fixed.class.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
	return ;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Fixed::Fixed(const int val)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = val << this->_fractBits;
	return ;
}

Fixed::Fixed(const float val)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (roundf((val * (1 << this->_fractBits))));
	return ;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_fixedPoint / (1 << this->_fractBits));
}

int Fixed::toInt( void ) const
{
	return this->_fixedPoint >> this->_fractBits;
}

Fixed &Fixed::operator++()
{
	this->_fixedPoint += 1;
	return *this;
}
Fixed &Fixed::operator--()
{
	this->_fixedPoint -= 1;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	this->_fixedPoint += 1;
	return old;
}
Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	this->_fixedPoint -= 1;
	return old;
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed Fixed::operator-(const Fixed &fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed &fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed)
{
	if (fixed.toFloat() != 0)
	{
		return Fixed(this->toFloat() / fixed.toFloat());
	}
	else
	{
		std::cout << "Exception: divide by 0! Result was set 0 to prevent errors." << std::endl;
		return (Fixed(0));
	}
}

bool Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}
bool Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

int  Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "Assignment operator called" << std::endl;
	this->_fixedPoint = raw;
	return;
}

Fixed &Fixed::operator=(Fixed const  &fix)
{
	// std::cout << "Assignment operator called" << std::endl;
	if (this != &fix)
	{
		this->_fixedPoint = fix.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &out,Fixed const &fix)
{
	return out << fix.toFloat();
}

Fixed        &Fixed::min(Fixed &fix1, Fixed &fix2)
{
	return ((Fixed)fix1 > (Fixed)fix2 ? fix2 : fix1);
}
const Fixed  &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	return ((Fixed)fix1 > (Fixed)fix2 ? fix2 : fix1);
}
Fixed        &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	return ((Fixed)fix1 > (Fixed)fix2 ? fix1 : fix2);
}
const Fixed  &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	return ((Fixed)fix1 > (Fixed)fix2 ? fix1 : fix2);
}
