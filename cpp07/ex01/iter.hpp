#pragma once

#include <iostream>

#include "Utils.hpp"

template <typename T>
void iter(T *array, size_t size, void (*f)(T &))
{
	size_t i = 0;
	while (i < size)
	{
		f(array[i]);
		i++;
	}
}
