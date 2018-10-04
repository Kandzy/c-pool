# ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>

class Fixed{
	private:
		int _fixedPoint;
		static const int _fractBits;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed &operator=(Fixed const  &fix);
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};

#endif