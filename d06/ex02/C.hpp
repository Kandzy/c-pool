#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class	C : public Base
{

	public:

		C(void);
		C(C &c);
		virtual ~C(void);
		C &operator=(C const &ref);

}; 


#endif