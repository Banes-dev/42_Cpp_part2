#pragma once

#include <iostream>

#include "Utils.hpp"

template <typename T>
class Array
{
	private:
		T *_elements;
		size_t _size;
	public:
		Array();
		Array(size_t recup_size);
		Array(const Array &copy);
		Array &operator=(const Array &copy);
		~Array();

		//  Other function
		T &operator[](size_t index);
		size_t size(void) const;
		class IndexOutOfBoundException : public std::exception {
			public :
				virtual const char *what() const throw();
		};
};
