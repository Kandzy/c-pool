#include <iostream>

template< typename T > void	swap(T &first, T &second){
	T temp = first;
	first = second;
	second = temp;
}

template< typename T > T &min(T &first, T &second) {
	if (first >= second) {
		return (second);
	}
	else {
		return (first);
	}
}

template< typename T > T &max(T &first, T &second) {
	if (first <= second) {
		return (second);
	}
	else {
		return (first);
	}
}

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	int x1 = 0;
	int y1 = 0;
	std::cout << "\033[1;34mx1 = \033[0m \033[1;32m" << x1 << "\033[0m, \033[1;34my1 = \033[0m \033[1;32m" << y1 << "\033[0m" << std::endl;
	::swap( x1, y1 );
	std::cout << "\033[1;34mx1 = \033[0m \033[1;32m" << x1 << "\033[0m, \033[1;34my1 = \033[0m \033[1;32m" << y1 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x1, y1 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x1, y1 ) << "\033[0m" << std::endl;
	int x2 = -256;
	int y2 = 256;
	std::cout << "\033[1;34mx2 = \033[0m \033[1;32m" << x2 << "\033[0m, \033[1;34my2 = \033[0m \033[1;32m" << y2 << "\033[0m" << std::endl;
	::swap( x2, y2 );
	std::cout << "\033[1;34mx2 = \033[0m \033[1;32m" << x2 << "\033[0m, \033[1;34my2 = \033[0m \033[1;32m" << y2 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x2, y2 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x2, y2 ) << "\033[0m" << std::endl;
	
	int x3 = 63453;
	int y3 = 64645645;
	std::cout << "\033[1;34mx3 = \033[0m \033[1;32m" << x3 << "\033[0m, \033[1;34my3 = \033[0m \033[1;32m" << y3 << "\033[0m" << std::endl;
	::swap( x3, y3 );
	std::cout << "\033[1;34mx3 = \033[0m \033[1;32m" << x3 << "\033[0m, \033[1;34my3 = \033[0m \033[1;32m" << y3 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x3, y3 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x3, y3 ) << "\033[0m" << std::endl;

	int x4 = -5365;
	int y4 = -4636346;
	std::cout << "\033[1;34mx4 = \033[0m \033[1;32m" << x4 << "\033[0m, \033[1;34my4 = \033[0m \033[1;32m" << y4 << "\033[0m" << std::endl;
	::swap( x4, y4 );
	std::cout << "\033[1;34mx4 = \033[0m \033[1;32m" << x4 << "\033[0m, \033[1;34my4 = \033[0m \033[1;32m" << y4 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x4, y4 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x4, y4 ) << "\033[0m" << std::endl;

	long x5 = 534534534534534;
	long y5 = 655676756756756;
	std::cout << "\033[1;34mx5 = \033[0m \033[1;32m" << x5 << "\033[0m, \033[1;34my5 = \033[0m \033[1;32m" << y5 << "\033[0m" << std::endl;
	::swap( x5, y5 );
	std::cout << "\033[1;34mx5 = \033[0m \033[1;32m" << x5 << "\033[0m, \033[1;34my5 = \033[0m \033[1;32m" << y5 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x5, y5 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x5, y5 ) << "\033[0m" << std::endl;

	double x6 = 0.54;
	double y6 = 0.23;
	std::cout << "\033[1;34mx5 = \033[0m \033[1;32m" << x6 << "\033[0m, \033[1;34my6 = \033[0m \033[1;32m" << y6 << "\033[0m" << std::endl;
	::swap( x6, y6 );
	std::cout << "\033[1;34mx6 = \033[0m \033[1;32m" << x6 << "\033[0m, \033[1;34my6 = \033[0m \033[1;32m" << y6 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x6, y6 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x6, y6 ) << "\033[0m" << std::endl;

	std::string x7= "abas";
	std::string y7= "dhfgh";
	std::cout << "\033[1;34mx7 = \033[0m \033[1;32m" << x7 << "\033[0m, \033[1;34my7 = \033[0m \033[1;32m" << y7 << "\033[0m" << std::endl;
	::swap( x7, y7 );
	std::cout << "\033[1;34mx7 = \033[0m \033[1;32m" << x7 << "\033[0m, \033[1;34my7 = \033[0m \033[1;32m" << y7 << "\033[0m" << std::endl;
	std::cout << "min( a, b ) = \033[1;32m" << ::min( x7, y7 ) << "\033[0m" << std::endl;
	std::cout << "max( a, b ) = \033[1;32m" << ::max( x7, y7 ) << "\033[0m" << std::endl;
	return (0);
}