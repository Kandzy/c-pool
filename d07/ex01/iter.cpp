#include <iostream>

template <typename T > void printArray(T &arg){
	std::cout << "\033[1;34m" << arg << "\033[1;0m" << std::endl;
}

template <typename T > void iter (T *arr, size_t size, void (*f)(T &param)){
	for (size_t i = 0; i < size; i++)
	{
		(*f)(arr[i]);
	}
}

int main()
{
	std::cout << "\033[1;31m" << "Int Array:" << "\033[1;0m" << std::endl;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11};
	iter(a, size_t(sizeof(a) / sizeof(int)), &printArray);

	std::cout <<std::endl << "\033[1;31m" << "String Array:" << "\033[1;0m" << std::endl;
	std::string b[] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz", "A", "LONGSTRING"};
	iter(b, sizeof(b) / sizeof(*b), &printArray);
	std::cout <<std::endl << "\033[1;31m" << "Char Array:" << "\033[1;0m" << std::endl;
	char c[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
	iter(c, sizeof(c) / sizeof(*c), &printArray);

	std::cout <<std::endl << "\033[1;31m" << "Double Array:" << "\033[1;0m" << std::endl;
	double d[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10, 11.11};
	iter(d, sizeof(d) / sizeof(*d), &printArray);

	std::cout <<std::endl << "\033[1;31m" << "Float Array:" << "\033[1;0m" << std::endl;
	float e[] = {1.15f, 2.25f, 3.35f, 4.45f, 5.55f, 6.65f, 7.75f, 8.85f, 9.95f, 10.15f, 11.15f};
	iter(e, sizeof(e) / sizeof(*e), &printArray);
	return 0;
}