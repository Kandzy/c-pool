#include "span.hpp"

Span::Span() : _size(0)
{
	_data.reserve(0);
	return ;
}

Span::Span(unsigned int n) : _size(n)
{
	_data.reserve(n);
	return ;
}

Span::Span(Span &span) {

	*this = span;
}

Span &Span::operator=(Span const &rSpan)
{
	this->_size = rSpan._size;
	this->_data = rSpan._data;
	return (*this);
}

void		Span::addNumber(int num)
{
	try
	{
		if (this->_data.size() < this->_size)
		{
			this->_data.push_back(num);
		}
		else
		{
			throw std::logic_error("\033[;31mExeption: Cant push one more number! Max Size!\033[;m");
		}
	}
	catch(std::logic_error ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	try{
		if (this->_size < this->_data.size() + std::distance(start, end))
		{
			throw std::logic_error("\033[;31mExeption: Cant push one more number!\033[;m");
		}
		else
		{
			for(; start != end; start++)
			{
				this->_data.push_back(*start);
			}
		}
	}
	catch(std::logic_error ex){
		std::cout << ex.what() << std::endl;
	}
}

int		Span::shortestSpan()
{
	try {
		if (this->_data.size() <= 1)
		{
			throw std::logic_error("\033[;31mExeption: Number of values < or == 1; Function returned value: -1\033[;m");
		}
		int	sSpan = this->longestSpan();
		std::vector<int>		tmp = this->_data;
		std::sort(tmp.begin(), tmp.end());
		for (unsigned long i = 0; i < tmp.size() - 1; i++)
		{
			if (tmp[i + 1] - tmp[i] < sSpan)
			{
				sSpan = tmp[i + 1] - tmp[i];
			}
		}
		return sSpan;
	}
	catch (std::logic_error ex)
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
}

int		Span::longestSpan()
{
	try
	{
		if (this->_data.size() <= 1)
			throw std::logic_error("\033[;31mExeption: Number of values < or == 1; Function returned value: -1\033[;m");
		std::vector<int>	max = this->_data;
		
		return (*std::max_element(max.begin(), max.end()) - *std::min_element(max.begin(), max.end()));
	} 
	catch (std::logic_error ex)
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}
}

Span::~Span()
{
	return ;
}