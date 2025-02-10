#pragma once

#include <iostream>  	// base
#include <vector> 		// vector
#include <algorithm> 	// algo

#include "Utils.hpp"


class NotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return ("\033[0;31mValue not found in container\033[0m");
		}
};

template <typename T>
typename T::iterator easyfind(T &list, size_t nb)
{
	typename T::iterator result;

	result = std::find(list.begin(), list.end(), nb);
	if (result != list.end())
		return (result);
	else
		throw (NotFoundException());
}
