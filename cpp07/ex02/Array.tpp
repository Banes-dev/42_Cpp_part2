#pragma once

#include "Utils.hpp"
#include "Array.hpp"

// Construtor etc
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(size_t recup_size) : _elements(new T[recup_size]), _size(recup_size)
{
}

template <typename T>
Array<T>::Array(const Array &copy) : _elements(NULL), _size(0)
{
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	if (this != &copy)
	{
		if (this->_elements)
			delete[] this->_elements;
		this->_size = copy._size;
		this->_elements = new T[this->_size];
		size_t i = 0;
		while (i < this->_size)
		{
			this->_elements[i] = copy._elements[i];
			i++;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_elements)
		delete[] this->_elements;
}

// Other function
template <typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->_size)
		throw Array::IndexOutOfBoundException();
	return (this->_elements[index]);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw()
{
	return "\033[0;31mIndex out of bound\033[0m";
}
