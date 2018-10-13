#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>

class Span{
	public:
							Span(void);
							Span(unsigned int n);
							Span(Span &span);
		Span				&operator=(Span const &rSpan);
		virtual				~Span(void);
		void				addNumber(int);
		void				addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int					shortestSpan();
		int					longestSpan();
	private:
		std::vector<int>	_data;
		unsigned int		_size;
};

#endif