#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <exception>

template<typename T>
class MutantStack : public std::stack<T>{
	private:
		typedef std::stack<T>					_mStack;
	public:
		MutantStack<T>() : _mStack() { return ; }

		MutantStack<T>(MutantStack<T> const &stack) : _mStack(stack) { return ; }
		using _mStack::operator=;

		~MutantStack<T>(void) { return ; }
		
		typedef typename _mStack::container_type::iterator iterator;

		T			top(void)  {
			try {
				if (this->_mStack::empty())
				{
					throw std::logic_error("\033[;31mException: Stack is empty! Return value: -1\033[;0m");
				}
				else
				{
					return (this->_mStack::top()); 
				}
			} catch (std::logic_error ex)
			{
				std::cout << ex.what() << std::endl;
			}
			return -1;
		}

		void		pop() {
			try{
				if (!this->_mStack::empty())
				{
					this->_mStack::pop();
				}
				else{
					throw std::logic_error("\033[;31mException: Stack is empty!\033[;0m");
				}
			} catch (std::logic_error ex)
			{
				std::cout<< ex.what() << std::endl;
			}
		}

		iterator	begin(){ return (this->_mStack::c.begin()); }
		iterator	end() { return (this->_mStack::c.end()); }
};

#endif