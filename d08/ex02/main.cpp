#include "mutantstack.hpp"




int		main()
{
	MutantStack<int> st;
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "empty?: " << st.empty() << std::endl;
	std::cout << st.top() << std::endl;
	st.pop();
	st.push(1);
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	st.push(4);
	for (int i = 0; i < 25; i++)
	{
		st.push(i);
	}
	std::cout << st.top() << std::endl;
	st.begin();
	MutantStack<int>::iterator it = st.begin();
	MutantStack<int>::iterator ite = st.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "\033[1;32mNEXT PART OF TESTS (BASIC) \033[1;0m" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	it = mstack.begin();
	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "size: " << mstack.size() << std::endl;
	std::stack<int> s(mstack);
	return (0);
}