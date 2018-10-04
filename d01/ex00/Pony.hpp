#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

#define pout std::cout
#define pin std::cout
#define nl std::endl
#define str std::string

class Pony {
	public:
		Pony(str name, int age, str color, bool ammunition);
		~Pony();
	private:
		str	name;
		str color;
		int age;
		bool ammunition;
		bool status;
	public:
		void setAmmunition(bool ammunition);
		void checkPonyIfReady(void);
};

#endif