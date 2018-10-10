#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class	A : public Base
{

	public:

		A(void);
		A(A &a);
		virtual ~A(void);
		A &operator=(A const &ref);

}; 


#endif