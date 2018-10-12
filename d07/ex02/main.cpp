#include <iostream>
#include "Array.hpp"


void test()
{
	Array<int> ar(10);
	for (unsigned int i = 0; i < ar.size(); i++) {
		std::cout << "array[" << i << "] = " << ar[i] << std::endl;
	}
	
	Array<int> ar2 = Array<int>(10);
	for (unsigned int i = 0; i < ar2.size(); i++) {
		ar2[i] = i;
		std::cout << "array[" << i << "] = " << ar2[i] << std::endl;
	}
	ar = ar2;
	for (unsigned int i = 0; i < ar.size(); i++) {
		std::cout << "array2[" << i << "] = " << ar[i] << std::endl;
	}
	for (unsigned int i = 0; i < ar2.size(); i++) {
		ar2[i] = 4;
	}
	for (unsigned int i = 0; i < ar2.size(); i++) {
		std::cout << "array[" << i << "] = " << ar2[i] << std::endl;
	}
	for (unsigned int i = 0; i < ar.size(); i++) {
		std::cout << "array2[" << i << "] = " << ar[i] << std::endl;
	}
	Array<int> tt;
	try {
		std::cout << tt[0] << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	Array<std::string> str(10);
	for (unsigned int i = 0; i < str.size(); i++)
	{
		std::cout << "str Array[" << i << "] = " << str[i] << std::endl;
	}
	for (unsigned int i = 0; i < str.size(); i++)
	{
		str[i] = "ghgfh";
		std::cout << "str Array[" << i << "] = " << str[i] << std::endl;
	}
	Array<double> dob(15);
	for (unsigned int i = 0; i < dob.size(); i++)
	{
		std::cout << "Double Array[" << i << "] = " << dob[i] << std::endl;
	}
	for (unsigned int i = 0; i < dob.size(); i++)
	{
		dob[i] =  i + i * (i/3.);
		std::cout << "Double Array[" << i << "] = " << dob[i] << std::endl;
	}
	Array<double> dob2(dob);
	for (unsigned int i = 0; i < dob2.size(); i++)
	{
		std::cout << "Double Array 2 [" << i << "] = " << dob2[i] << std::endl;
	}
}

int		main()
{
	test();
	return (0);
}