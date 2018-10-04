# ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fixedPoint;
		static const int _fractBits;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed &operator=(Fixed const  &fix);
		
		float toFloat( void ) const;
		int toInt( void ) const;
		int	getRawBits(void) const;
		void setRawBits( int const raw);
};

std::ostream &operator<<(std::ostream &out,Fixed const &fix);

#endif