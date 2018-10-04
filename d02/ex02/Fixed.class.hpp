#ifndef FIXED_CLASS_HPP
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
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);
		bool operator<(const Fixed &fixed);
		bool operator>(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator>=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator!=(const Fixed &fixed);

		static Fixed        &min(Fixed &fix1, Fixed &fix2);
		const static Fixed  &min(const Fixed &fix1, const Fixed &fix2);
		static Fixed        &max(Fixed &fix1, Fixed &fix2);
		const static Fixed  &max(const Fixed &fix1, const Fixed &fix2);
		
};

std::ostream &operator<<(std::ostream &out,Fixed const &fix);

#endif