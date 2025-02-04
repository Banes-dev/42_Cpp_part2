#pragma once

#include <iostream>
#include <stdint.h>

#include "Utils.hpp"
#include "Data.hpp"

class Serializer
{
    private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
	public:
		virtual ~Serializer(void) = 0;

		// Other function
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
