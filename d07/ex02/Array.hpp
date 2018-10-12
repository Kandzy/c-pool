#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array{
	public:
		Array<T>(void) : _array(new T [0]()), _size(0) { return ; }
		
		Array<T>(unsigned int n) : _array(new T [n]()) ,_size(n) { return ; }

		Array<T> &operator=(Array<T> const &ar) {
			if (this->_array){
				delete [] this->_array;
			}
			this->_size = ar.size();
			this->_array = new T[ar.size()]();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = ar[i];
			return *this;
		}
		Array<T>(Array<T> const &ar) {
			this->_size = ar.size();
			this->_array = new T[ar.size()]();
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = ar[i];
		}

		T	&operator[](unsigned int i) const {
			if (i >= this->_size)
				throw std::exception();
			return this->_array[i];
		}
		
		unsigned int size( void ) const { return this->_size; }

		~Array<T>(void) {
			if (this->_array){
				delete [] this->_array; 
			}
		}
	private:

	T				*_array;
	unsigned int	_size;
};

#endif