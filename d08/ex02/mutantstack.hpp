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
	public:
		MutantStack<T>() { return ; }

		MutantStack<T>(MutantStack<T> const &stack) : _stackList(stack._stackList) { return ; }

		MutantStack<T> &operator=(MutantStack<T> const &stack)
		{
			this->_stackList = stack._stackList;
			return (*this);
		}

		~MutantStack<T>(void) { return ; }

		typedef std::list<int>::iterator iterator;

		T			top(void) const { return (this->_stackList.front()); }
		bool		empty(void) const { return (this->_stackList.empty()); }
		int			size(void) const { return (this->_stackList.size()); }
		void		push(T const &val) { this->_stackList.push_front(val); }
		void		pop() {
			try{
				if (!this->empty())
				{
					this->_stackList.pop_front();
				}
				else{
					throw std::logic_error("\033[;31mException: Stack is empty!\033[;0m");
				}
			} catch (std::logic_error ex)
			{
				std::cout<< ex.what() << std::endl;
			}
		}
		iterator 	begin() { return (this->_stackList.begin()); }
		iterator	end() { return (this->_stackList.end()); }
		
	private:
		std::list<T>	_stackList;
};

#endif